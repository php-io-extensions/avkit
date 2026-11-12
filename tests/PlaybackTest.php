<?php

declare(strict_types=1);

beforeEach(function (): void {
    $this->app = NSApplication::sharedApplication();
});

it('registers the playback classes, CMTime and its functions itself', function (): void {
    foreach ([AVPlayer::class, AVPlayerItem::class, AVPlayerView::class, CMTime::class, AVPlayerItemStatus::class,
        AVPlayerTimeControlStatus::class, AVPlayerActionAtItemEnd::class, AVPlayerViewControlsStyle::class] as $class) {
        expect((new ReflectionClass($class))->getExtensionName())->toBe('avkit');
    }
    expect((new ReflectionFunction('CMTimeMake'))->getExtensionName())->toBe('avkit')
        ->and((new ReflectionClass(NSURL::class))->getExtensionName())->toBe('appkit')
        ->and(is_subclass_of(AVPlayerView::class, NSView::class))->toBeTrue()
        ->and(is_subclass_of(AVPlayer::class, NSObject::class))->toBeTrue();
});

it('plays a clip to its end and reports failure for a missing file', function (): void {
    $url = NSURL::fileURLWithPath(videoFixture());
    $item = AVPlayerItem::playerItemWithURL($url);
    $player = AVPlayer::playerWithPlayerItem($item);
    $view = AVPlayerView::initWithFrame(new NSRect(0, 0, 64, 64));
    $view->setPlayer($player);
    $view->setControlsStyle(AVPlayerViewControlsStyle::NONE);
    $player->setMuted(true);
    $ended = 0;
    expect($item->duration()->flags & kCMTimeFlags_Indefinite)->toBe(kCMTimeFlags_Indefinite);
    $token = NSNotificationCenter::defaultCenter()->addObserverForNameObjectQueueUsingBlock(AVPlayerItemDidPlayToEndTimeNotification, $item, NSOperationQueue::mainQueue(), function () use (&$ended): void {
        $ended++;
    });

    $player->play();
    // A closure with use (&$ended): an arrow function would capture the counter by value and never see the increment.
    $finished = pumpUntil($this->app, function () use (&$ended): bool {
        return $ended > 0;
    }, 5.0);
    NSNotificationCenter::defaultCenter()->removeObserver($token);

    expect($finished)->toBeTrue()
        ->and($ended)->toBe(1)
        ->and($view->player())->toBe($player)
        ->and($view->controlsStyle())->toBe(AVPlayerViewControlsStyle::NONE)
        ->and($player->currentItem())->toBe($item)
        ->and($player->isMuted())->toBeTrue()
        ->and($player->timeControlStatus())->toBe(AVPlayerTimeControlStatus::PAUSED)
        ->and($item->status())->toBe(AVPlayerItemStatus::READY_TO_PLAY)
        ->and($item->error())->toBeNull()
        ->and(round(CMTimeGetSeconds($item->duration())))->toBe(1.0)
        ->and(round(CMTimeGetSeconds($player->currentTime())))->toBe(1.0);

    $player->seekToTime(CMTimeMakeWithSeconds(0.5, 600));
    $player->setRate(0.0);
    $player->pause();
    expect($player->rate())->toBe(0.0);

    $bad = AVPlayerItem::playerItemWithURL(NSURL::fileURLWithPath('/nope/clip.mp4'));
    $player->replaceCurrentItemWithPlayerItem($bad);
    pumpUntil($this->app, fn () => $bad->status() !== AVPlayerItemStatus::UNKNOWN, 5.0);
    expect($bad->status())->toBe(AVPlayerItemStatus::FAILED)
        ->and($bad->error())->toBeInstanceOf(NSError::class)
        ->and($bad->error()->domain())->toBe('AVFoundationErrorDomain');

    $view->setPlayer(null);
    expect($view->player())->toBeNull();
});

it('comes back from appkit as itself and outlives its superview', function (): void {
    $parent = NSView::initWithFrame(new NSRect(0, 0, 64, 64));
    $view = AVPlayerView::initWithFrame(new NSRect(0, 0, 32, 32));
    $parent->addSubview($view);

    $back = $parent->subviews()[0];
    expect($back)->toBeInstanceOf(AVPlayerView::class)
        ->and($back)->toBe($view);

    $view->removeFromSuperview();
    unset($parent, $back);
    $view->setControlsStyle(AVPlayerViewControlsStyle::MINIMAL);
    expect($view->controlsStyle())->toBe(AVPlayerViewControlsStyle::MINIMAL);
});

it('converts between seconds and CMTime', function (): void {
    $time = CMTimeMakeWithSeconds(1.5, 600);

    expect($time->value)->toBe(900)
        ->and($time->timescale)->toBe(600)
        ->and(CMTimeGetSeconds($time))->toBe(1.5)
        ->and($time->flags)->toBe(kCMTimeFlags_Valid)
        ->and($time->epoch)->toBe(0)
        ->and(CMTimeGetSeconds(new CMTime(3, 2, kCMTimeFlags_Valid, 0)))->toBe(1.5)
        ->and(CMTimeGetSeconds(new CMTime(0, 0, kCMTimeFlags_Valid | kCMTimeFlags_PositiveInfinity, 0)))->toBe(INF)
        ->and(is_nan(CMTimeGetSeconds(new CMTime(0, 0, 0, 0))))->toBeTrue();

    $unset = new CMTime(1, 1, kCMTimeFlags_Valid, 0);
    unset($unset->timescale);
    expect(fn () => CMTimeGetSeconds($unset))->toThrow(Error::class);
});

it('takes every CMTime field and binds the CMTimeFlags constants', function (): void {
    expect(fn () => new CMTime(1, 1))->toThrow(ArgumentCountError::class)
        ->and((new ReflectionProperty(CMTime::class, 'value'))->hasDefaultValue())->toBeFalse()
        ->and([kCMTimeFlags_Valid, kCMTimeFlags_HasBeenRounded, kCMTimeFlags_PositiveInfinity, kCMTimeFlags_NegativeInfinity, kCMTimeFlags_Indefinite])
        ->toBe([1, 2, 4, 8, 16]);
});

it('makes and compares CMTimes', function (): void {
    $time = CMTimeMake(900, 600);

    expect([$time->value, $time->timescale, $time->flags, $time->epoch])->toBe([900, 600, kCMTimeFlags_Valid, 0])
        ->and(CMTimeGetSeconds($time))->toBe(1.5)
        ->and(CMTimeCompare(CMTimeMake(1, 2), CMTimeMake(2, 2)))->toBe(-1)
        ->and(CMTimeCompare(CMTimeMake(3, 2), CMTimeMake(3, 2)))->toBe(0)
        ->and(CMTimeCompare(CMTimeMake(3, 2), CMTimeMake(1, 2)))->toBe(1);
});

it('keeps playing past the end when the end action is none', function (): void {
    $player = AVPlayer::playerWithPlayerItem(null);

    expect($player->actionAtItemEnd())->toBe(AVPlayerActionAtItemEnd::PAUSE);
    $player->setActionAtItemEnd(AVPlayerActionAtItemEnd::NONE);
    expect($player->actionAtItemEnd())->toBe(AVPlayerActionAtItemEnd::NONE);
});

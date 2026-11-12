<?php

declare(strict_types=1);

it('makes a CMTimeRange and finds its end', function (): void {
    $range = CMTimeRangeMake(CMTimeMake(1, 1), CMTimeMake(2, 1));

    expect($range)->toBeInstanceOf(CMTimeRange::class)
        ->and(CMTimeGetSeconds($range->start))->toBe(1.0)
        ->and(CMTimeGetSeconds($range->duration))->toBe(2.0)
        ->and(CMTimeGetSeconds(CMTimeRangeGetEnd($range)))->toBe(3.0)
        ->and(CMTimeGetSeconds(CMTimeRangeGetEnd(new CMTimeRange(CMTimeMake(1, 2), CMTimeMake(1, 2)))))->toBe(1.0);
});

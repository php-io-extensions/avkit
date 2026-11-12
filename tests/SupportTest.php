<?php

declare(strict_types=1);

require_once __DIR__.'/../scripts/support.php';

/** A text AST dump of a class, a subclass, a delegate protocol, a CoreMedia function and a Foundation class, as clang prints them. */
function supportTestAst(): string
{
    $av = '/SDK/System/Library/Frameworks/AVFoundation.framework/Headers/';
    $cm = '/SDK/System/Library/Frameworks/CoreMedia.framework/Headers/';

    return implode("\n", [
        'TranslationUnitDecl 0x1 <<invalid sloc>> <invalid sloc>',
        "|-ObjCInterfaceDecl 0x2 <{$av}AVAsset.h:10:1, line:20:2> line:10:12 AVAsset",
        "| |-ObjCPropertyDecl 0x3 <line:12:1, col:30> col:30 duration 'CMTime' readonly atomic",
        "| |-ObjCMethodDecl 0x4 <line:12:30> col:30 implicit - duration 'CMTime'",
        "| |-ObjCMethodDecl 0x5 <line:14:1, col:60> col:1 - oldCall: 'void'",
        "| | `-AvailabilityAttr 0x6 <col:1> macos 10.7 13.0 0 \"\" \"\" 0",
        "|-ObjCInterfaceDecl 0x7 <{$av}AVAsset.h:30:1, line:40:2> line:30:12 AVURLAsset",
        "| |-super ObjCInterface 0x2 'AVAsset'",
        "| `-ObjCMethodDecl 0x8 <line:31:1, col:60> col:1 + URLAssetWithURL:options: 'instancetype'",
        "|-ObjCProtocolDecl 0x9 <{$av}AVPlayerItemOutput.h:5:1, line:9:2> line:5:11 AVPlayerItemOutputPullDelegate",
        "| `-ObjCMethodDecl 0xa <line:6:1, col:30> col:1 - outputMediaDataWillChange: 'void'",
        "|-FunctionDecl 0xb <{$cm}CMTime.h:50:1, col:40> col:30 CMTimeMake 'CMTime (int64_t, int32_t)' extern",
        "|-ObjCInterfaceDecl 0xc </SDK/System/Library/Frameworks/Foundation.framework/Headers/NSObject.h:5:1, line:9:2> line:5:12 NSObject",
        '| `-ObjCMethodDecl 0xd <line:6:1, col:10> col:1 + new \'instancetype\'',
    ]);
}

it('counts class members and C functions of the measured headers, without protocols, deprecated members or Foundation', function (): void {
    expect(support_counted(supportTestAst()))->toBe([
        'AVAsset' => ['-[AVAsset duration]'],
        'AVURLAsset' => ['+[AVURLAsset URLAssetWithURL:options:]'],
        'functions' => ['CMTimeMake'],
    ]);
});

it('marks a member bound through a subclass stub and a function stub', function (): void {
    $ast = supportTestAst();
    $md = support_render(support_counted($ast), ['AVURLAsset' => ['duration' => true, 'URLAssetWithURLOptions' => true], '' => ['CMTimeMake' => true]], 'test', '2026-11-11', support_parents($ast));

    expect(support_totals($md))->toBe([3, 3]);
});

it('keeps SUPPORT.md and the README badge current', function (): void {
    exec(escapeshellarg(PHP_BINARY).' '.escapeshellarg(__DIR__.'/../scripts/support.php').' --check', $output, $status);

    expect($status)->toBe(0, implode("\n", $output));
});

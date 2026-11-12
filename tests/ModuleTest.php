<?php

declare(strict_types=1);

it('loads with its version', function () {
    expect(extension_loaded('avkit'))->toBeTrue()
        ->and(phpversion('avkit'))->toBe('0.11.2');
});

it('requires appkit', function () {
    expect((new ReflectionExtension('avkit'))->getDependencies())->toBe(['appkit' => 'Required']);
});

it('refuses to start without appkit instead of crashing', function () {
    $output = [];
    exec(escapeshellarg(PHP_BINARY).' -n -d extension='.escapeshellarg(ini_get('extension_dir').'/avkit.so').' -r "echo 1;" 2>&1', $output);

    expect(implode("\n", $output))->toContain('appkit');
});

#! /usr/bin/env perl

use strict;
use warnings;
use v5.10;
use File::Compare;

my $fst_dir = shift || die "Need to specify two directories to compare to.";
my $snd_dir = shift || die "Need to specify two directories to compare to.";

my $suff = "_STATS.txt";

my @fst_files = <$fst_dir/*/*$suff>;
my @snd_files = <$snd_dir/*/*$suff>;

my $bad_matches = 0;

for (@fst_files) {
    my ($end) = $_ =~ m|(/[^/]+/[^/]+$suff)$|;
    my ($match) = grep { $_ =~ m/${end}$/ } @snd_files;

    if ($match) {
        if (compare($_, $match)) {
            say "$end is different!";
            `diff $_ $match`;
            $bad_matches += 1;
        }
    }
    else {
        say "No file $snd_dir$end";
        $bad_matches += 1;
    }
}

if ($bad_matches) {
    say "$bad_matches files don't match...";
    exit 1;
}

say "All files match!";

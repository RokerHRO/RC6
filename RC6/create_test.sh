#!/bin/sh

grep ecb-mode-test < rc6.testvec | 
	sed -e 's|(:ecb-mode-test #h"\([0-9A-F]*\)" #h"\([0-9A-F]*\)" #h"\([0-9A-F]*\)")|./test_rc6 \1 \2 \3 \&\& |g' \
	> test.sh

echo 'echo All done.' >> test.sh

chmod 755 test.sh

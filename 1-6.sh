#!/bin/sh

echo -n 'EOF as first char:     '; echo -n | 1-6.o
echo
echo -n 'Non-EOF as first char: '; echo | 1-6.o
echo

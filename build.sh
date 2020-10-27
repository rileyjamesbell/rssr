#!/bin/sh

CC="gcc"
MAIN="nciout.c"
OUT="nciout"
LIBS=$(pkg-config --libs ncursesw)

$CC $MAIN $LIBS -o $OUT

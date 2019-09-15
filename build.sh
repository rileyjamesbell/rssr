#!/bin/sh

#Makefiles are overrated

nciout(){
	CC="gcc"
	MAIN="nciout.c"
	OUT="nciout"
	LIBS=$(pkg-config --libs ncursesw)

	$CC $MAIN $LIBS -o $OUT
}

case $1 in
	"all"|"")
		echo "Building nciout"
		nciout
		;;
	"nciout")
		nciout
		;;
	*)
		echo "Specify which program to build"
		return 1
		;;
esac

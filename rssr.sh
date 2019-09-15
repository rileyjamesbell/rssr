#!/bin/sh

dn=$(dirname "$0")
[ -x "$dn/tkread.py" ] && reader=$dn/tkread.py
[ -x "$dn/tkread" ] && reader=$dn/tkread
if [ -z "reader" ]
then
	echo "Unable to locate reader.">/dev/stderr
	exit
fi

sselp| #Get the current selection ( http://tools.suckless.org/x/sselp/ )
tr ' ' '\n'| #Break up by words
sed -r "/^\s*$/d"| #Remove blank lines
$dn/nciout $@| #Output at intervals
python3 $reader #Display

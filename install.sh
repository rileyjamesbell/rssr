#!/bin/sh

case $1 in
	"install"|"i"|"")
		if [ ! -x "nciout" ]
		then
			echo "nciout does not exist or does not have execution permissions">/dev/stderr
			exit
		fi

		cp nciout /bin/nciout
		cp rssr.sh /bin/rssr
		cp tkread.py /bin/tkread
		;;
	"uninstall"|"remove")
		rm /bin/nciout
		rm /bin/rssr
		rm /bin/tkread
		;;
esac

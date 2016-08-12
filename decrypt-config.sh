#!/bin/sh
echo "*********************"
echo "*  DECRYPT CONFIG   *"
echo "*********************"

ostype()
{
    osname=`uname -s`
	OSTYPE=UNKNOWN
	case $osname in
		"Darwin")
		OSTYPE="MAC"
		;;
		"Linux")
		OSTYPE="LINUX"
		;;
		*)
		OSTYPE="MAC"
		;;
	esac
	return 0
}

ostype
echo $OSTYPE

if [[ $OSTYPE -eq "LINUX" ]]; then
	echo 'OS is Linux'
else
	echo 'OS is MAC'
fi
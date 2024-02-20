#!/bin/bash
read -p "" dir
if [ -d $dir ]
then
find $dir -empty -type d -delete
else
	echo "Invalid"
	exit 0;
fi

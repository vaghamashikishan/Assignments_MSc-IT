#!/bin/bash
if [ $# -gt 9 ]
then
	echo "Enter Valid Numbder "
else
	for n in $*
	do
		sum=`expr $sum + $n`
	done
	echo "SUM : $sum"
fi

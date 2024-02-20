#!/bin/bash
read -p "" rmdup
if [ -f $rmdup ]
then
	sort $rmdup | uniq -u | tee output.txt
else
	echo ""
exit 0;
fi

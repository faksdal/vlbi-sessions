#!/bin/bash


if [ $# -eq 0 ]
then
	echo "No parameters specified!"
	echo "Usage: $0 <year> <output file> <date range to filter (for instance: '2024-04\|2024-05)'> <0|1 (download data)>"
	exit 1
fi

if [ "$4" ]
then
	wget https://ivscc.gsfc.nasa.gov/sessions/$1
fi

#html2text -width $(tput cols) $1 >> $2
#html2text -width $(tput cols) $1 | grep -n '2024-04\|2024-05\|2024-06'

html2text -width $(tput cols) $1 | grep -n '' >> allSessions.txt
html2text -width $(tput cols) $1 | grep -n $3 >> $2$3

echo 'Program name: '$0
echo 'Param #1: '$1
echo ''\'$2''\'
echo $3
echo $4
#html2text -width $(tput cols) $1 | grep -n (''\'$2''\')


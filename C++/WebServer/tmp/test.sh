#!/bin/bash

num=0
oldIFS=$IFS
#IFS=$'\n'

for i in `cat a.txt`;do
	echo $i
	num=`expr $num + 1`
	echo num::$num
done
echo num:$num
IFS=$oldIFS

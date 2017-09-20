#!/bin/bash
for (( i=1 ; i <= 8000 ; i++ ))
do
	echo "Performing Traceroute number: " $i 
	traceroute www.prodisney.ru >> dumpfile
	sleep 3s
done

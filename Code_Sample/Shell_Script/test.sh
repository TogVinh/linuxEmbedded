#!/bin/bash

read N
declare -a array
read -a array

declare num_alone

if [ $((N%2)) == 0 ]; then
	echo "wrong input-- Number have to odd number"
else
	if [ ${#array[@]} != $N ]; then
		echo "the number of array not mach"
	else
		for index in ${array[@]}
		do
			count=0
			for index2 in ${array[@]}
			do
				if [ $index == $index2 ] ; then
					count=$((count+1))
				fi
			done
			
			if [ $count == 1 ]; then
				num_alone=$index
				echo $num_alone
				#exit
			fi
		done
		#echo $num_alone
	fi
 
fi

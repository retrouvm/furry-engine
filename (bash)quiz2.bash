#!/bin/bash


lineNumber=1 #line number currently reading
#Assume the first line is line number 1
count=0 #numbers divisible by 3
# check if it is divisible by 3

while read num #read the num from the file
do
  if (( num % 3 == 0 )); then # if num%3, print the line number and increment the count at the end increment the lineNum
    #echo "$lineNumber"
    (( count=count+1 ))
  fi
  (( lineNumber=lineNumber+1 ))
done

if (( count > 10 )); then #if the total number of lines not divisible by 3 is greater than 10, print big
  echo "big"
else
  echo "small"
fi

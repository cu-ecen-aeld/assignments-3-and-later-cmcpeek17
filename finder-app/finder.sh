#!/bin/bash

if [ ! $# -eq 2 ]
then
    echo "correct amoount of inputs not supplied"
    exit 1
fi

if [ ! -d $1 ]
then
    echo "$1 not a directory"
    exit 1
fi

num_matches=$(grep -rc $2 $1/* | wc -l)
num_files=$(ls $1 -1 | wc -l)
echo "The number of files are $num_files and the number of matching lines are $num_matches"

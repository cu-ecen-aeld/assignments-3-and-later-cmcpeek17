#!/bin/bash

if [ ! $# -eq 2 ]
then
   echo "wrong amount of inputs provided"
fi

if [ ! -f $1 ]
then
    mkdir -p $(dirname $1)
fi

if ! echo $2 > $1 
then
    echo "file could not be created" 
    exit 1
fi

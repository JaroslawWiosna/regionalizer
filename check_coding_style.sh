#!/bin/bash -e

git diff > diff.txt

if [ -s diff.txt ]
then
    rm -rf diff.txt
    exit 0
else
    rm -rf diff.txt
    exit 1
fi

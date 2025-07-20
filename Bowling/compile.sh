#! /bin/bash

if [[ $# -eq 0 ]]; then
    echo usage: ./compille file.c

elif [[ $# -eq 1 ]]; then
    target=$1

# elif [[ $# -eq 2 ]]; then
#     target=$1
#     arg=$2
fi

#simple compiler script to ease the process
if [[ $target =~ \.c$ ]]; then
    out=${target/.c/.x}
    gcc $target -o $out
else
    echo usage: ./compille file.c
fi
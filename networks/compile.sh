#!/bin/bash

file=$1

if [ -e $file ]; then
    echo "Exists"
    if [[ "$file" == *.c ]]; then
        echo "Compiling possible"

        gcc $file -o out.x
        ./out.x
        rm *.x
    else
        echo "Compiling not possible"
    fi
    
else
    echo "Doesn't exist"
fi



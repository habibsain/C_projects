#! /bin/bash

gccflag="-I../include/ -Wall"
#src=../src/mem.c
src=bowling_game.c
target=$1
out=${target/.c/.x}

if [[ $# -eq 0 ]]; then
    echo "usage: ./compille file.c flag(none = Includes mem.h; 1 = without mem.h)"
    exit 1   
fi

#flag:
#no flag

#simple compiler script to ease the process
if [[ $target =~ \.c$ && $# -eq 1 ]]; then
    
    gcc $gccflag $src $target -o $out

elif [[ $target =~ \.c$ && $2 -eq 1 ]]; then
    gcc  $target -o $out

elif [[ $target == clean ]]; then
    rm *.x

else
    echo "usage: ./compille file.c flag(none = Includes mem.h; 1 = without mem.h)"
fi
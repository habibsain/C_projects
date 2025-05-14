#!/bin/bash

echo Without pointers:
gcc pointers.c -o pointers.x

./pointers.x >> text.txt

echo With pointers:

gcc pointers2.c -o pointers2.x
./pointers2.x >> text2.txt



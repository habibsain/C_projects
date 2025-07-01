#!/bin/bash

gcc driver.c dyn_arr.c -o driver.x

./driver.x

rm *.x
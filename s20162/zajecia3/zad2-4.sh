#!/bin/bash

for nazwa in ${ls -a *.c}; do
    cc $nazwa -o ${nazwa%.*}
done
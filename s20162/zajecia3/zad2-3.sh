#!/bin/bash

IFS=$'\n'
for i in $(ls -l); do
    echo "patrzcie panstwo oto plik: $i"
done
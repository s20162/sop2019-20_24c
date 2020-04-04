#!/bin/bash

# Napisz skrypt, który wypisze listę plików i katalogów bieżącego katalogu poprzedzając każdą nazwę pliku tekstem "Patrzcie Państwo, oto plik: "

files=$(ls -1)
IFS=$'\n'

for i in $files; do
    echo "Patrzcie Państwo, oto plik: $i"
done

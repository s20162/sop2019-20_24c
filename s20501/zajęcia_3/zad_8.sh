#!/bin/bash

# Napisz skrypt, który dla każdego pliku w bieżącym katalogu, który ma rozszerzenie .c wykona taką komendę:  cc (tunazwapliku) -o (tunazwaplikubezrozszerzenia)

files=$(ls -1)
IFS=$'\n'

for i in $files; do

    name="${i%.*}"
    extension="${i##*.}"

    if [ "${extension}" == "c" ]; then
        cc $i -o $name
    fi
done

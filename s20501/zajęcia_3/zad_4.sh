#!/bin/bash

# Napisz skrypt, który sprawdzi, czy w bieżącym katalogu jest więcej niż 5 plików. Jeśli tak, to wypisze odpowiedni komunikat z informacją że tak jest

count=$(find . -maxdepth 1 -type f | wc -l)

if [ $count -gt 5 ]; then
    echo Jest więcej niż 5 plików

fi

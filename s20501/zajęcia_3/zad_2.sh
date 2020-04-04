#!/bin/bash

# Napisz skrypt, który sprawdzi, czy istnieje plik config.cfg w bieżącym katalogu. Jeśli taki plik istnieje, to niech go wykona. Jeśli nie istnieje, to niech sprawdzi, czy podano argument i wykona plik o nazwie takiej jak wartość argumentu (parametru) skryptu. Jeśli żadne z powyższych nie nastąpiło, to niech wyświetli komunikat o błędzie.
currentDir=$(pwd)

if [ -e $currentDir/config.cfg ]; then
    $currentDir/config.cfg
elif [ $# -gt 0 ] && [ -e $currentDir/$1 ]; then
    $currentDir/$1
else
    echo Blad
fi

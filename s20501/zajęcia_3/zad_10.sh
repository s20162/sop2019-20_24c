#!/bin/bash

#Przygotuj skrypt z funkcją która będzie wypisywała tekst pokolorowany na zadany kolor. Niech funkcja ta przyjmuje dwa argumenty - tekst i kolor.

function color() {
    echo -e "\033[$2m$1\e[0m"
}

color $1 $2

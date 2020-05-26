#!/bin/bash

ilosc=&(find . -maxdepth 1 -type f | wc -l)

if [ $ilosc -gt5 ]
then
    echo jest wiecej niz 5 plikow
fi
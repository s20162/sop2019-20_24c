#!/bin/bash

katalog=$(pwd)

if [ -e $katalog/config.cfg ]
then
    $katalog/config.cfg
elif [ $# -gt 0 ] && [-e $katalog/$1 ]
then
    $katalog/$1
else
    echo Komunikat o bledzie
fi
#!/bin/bash

name="$0"

x=${name:(${#name}-3)}


if [ $x = ".sh" ]
then
    echo "plik ma juz rozszerzenie"
else
    mv $name $name.sh
fi
#!/bin/bash

function kolor {
    echo -e "\e[$2m$1\e[0m"
}

kolor $1 $2
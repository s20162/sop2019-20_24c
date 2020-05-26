#!/bin/bash

x=tekst
echo $x
export x
bash
echo $x

x=Tekst dluzszy
echo $x

x="Teskt dluzszy"
echo $x

x="Tekst 1"
y="tekst:$x"
echo "$y"
y='tekst:$x'
echo "$y"
y=tekst:$x
echo "$y"
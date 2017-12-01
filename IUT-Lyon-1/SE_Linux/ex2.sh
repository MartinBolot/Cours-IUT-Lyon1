#!/bin/bash
tempsRestant=5
while test $tempsRestant -gt 0
  do
    echo $tempsRestant
    ((tempsRestant=tempsRestant-1))
    sleep 1
  done
echo "!! Decollage"

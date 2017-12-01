#!/bin/bash
if test $# -gt 0
  then
    ls $1
  else
    echo "Il faut passer un repertoire en parametre"
fi

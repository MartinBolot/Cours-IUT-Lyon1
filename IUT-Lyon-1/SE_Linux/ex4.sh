#!/bin/bash
if test $# -eq 1
  then
    echo "ok"
    ls $1 > /dev/null
    if test $? -eq 0
      then
        echo "700"
        for fichier in $1/*
        do
            chmod 700 $fichier
        done
    else
        echo "L argument n est pas un repertoire ou n existe pas"
    fi
elif test $# -gt 1
  then
    echo "Il faut passer un seul repertoire en parametre"
else
    echo "Il faut passer au moins un repertoire en parametre"
fi

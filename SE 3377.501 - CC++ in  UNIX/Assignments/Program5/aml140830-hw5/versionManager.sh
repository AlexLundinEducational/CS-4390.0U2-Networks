#!/bin/bash
vers_dir=$1
fileName=$2
FILESTOKEEP=$3
# find all files with the supplied name, then reverse sort, then filter the number to keep, delete anything remaining
find $vers_dir/ -name "$2" | sort -r | awk -v FILESTOKEEP=$FILESTOKEEP '{if (NR>FILESTOKEEP) print $1}' | xargs rm
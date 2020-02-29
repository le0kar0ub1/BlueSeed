#!/bin/sh

PREFIX=$(realpath $(dirname $0))

TARGETSYSCAL="$PREFIX/arch/$1"
FILEPATH=$2
FILEHEAD="$PREFIX/filehead"
FILETAIL="$PREFIX/filetail"

rm -f $FILEPATH

cat $FILEHEAD > $FILEPATH

if [ ! -f $TARGETSYSCAL ]; then
    echo "Unhandle syscall for the targeted architecture...."
    source $PREFIX/arch/unhandle
else
    source $TARGETSYSCAL
fi


echo -e "\n$MAPPED" >> $FILEPATH

cat $FILETAIL >> $FILEPATH

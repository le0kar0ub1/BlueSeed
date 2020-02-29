#!/bin/sh

ARCHREALPATH=$(realpath arch)
TARGETSYSCAL=$1
FILEPATH=$(realpath $2)
FILEHEAD=filehead
FILETAIL=filetail

rm -f $FILEPATH

cat $FILEHEAD > $FILEPATH

if [ ! -f $ARCHREALPATH/$TARGETSYSCAL ]; then
    echo "Unhandle syscall for the targeted architecture...."
    source $ARCHREALPATH/unhandle
else
    source $ARCHREALPATH/$TARGETSYSCAL
fi


echo -e "\n$MAPPED" >> $FILEPATH

cat $FILETAIL >> $FILEPATH

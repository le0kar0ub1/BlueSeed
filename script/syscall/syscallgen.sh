ARCH=$1
FILEPATH=$2
FILEHEAD=filehead
FILETAIL=filetail

rm -f $FILEPATH

cat $FILEHEAD > $FILEPATH

if [ ! -f $ARCH ]; then
    echo "Unhandle syscall for the targeted architecture...."
    source ./arch/unhandle
else
    source ./arch/$ARCH
fi


echo -e "$MAPPED" >> $FILEPATH

cat $FILETAIL >> $FILEPATH

#!/usr/bin/env bash

FILENAME=$1;

if [ -d $FILENAME ]; then
  echo "Folder already exists!"
  exit 
fi

mkdir ./$FILENAME
cd ./$FILENAME
mkdir include
cd ./include && touch $FILENAME.h
cd ..
touch $FILENAME.c main.c compile.sh run.sh

cat << EOF > compile.sh
#!/usr/bin/env bash

BIN_DIRECTORY="bin"
CC="gcc"
FLAGS="-std=c99 -Iinclude -I../bin"

declare -a cFiles
for file in *.c
do
  cFiles=(${cFiles[@]} "$file")
done

if [ ! -d $BIN_DIRECTORY ]; then
  mkdir ./bin
fi

$CC "${cFiles[@]}" -o ./bin/main $FLAGS
EOF


cat << EOF > run.sh
#!/usr/bin/env bash
./compile.sh && ./bin/$FILENAME
EOF

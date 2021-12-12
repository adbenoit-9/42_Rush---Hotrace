#!/bin/sh

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

NB_TEST=$(ls ./infile | wc -l)

cd ..
make re
cp hotrace test/.
norminette .
cd test
echo ""

index=1
while ((index <= $NB_TEST))
do
    ./hotrace < ./infile/infile_$index > /dev/null
	var=$( { time ./hotrace < ./infile/infile_$index >./outfile/outfile_$index; } 2>&1 | grep real | cut -c8-13 )
	if diff -q ./outfile/outfile_$index ./expected/outfile_$index > /dev/null
	then
	  printf "$BOLDGREEN Check $index :		 		[success]$RESET $BOLDBLUE[$var]$RESET\n"
	else
	  printf "$BOLDRED Check $index :	 			[error]$RESET\n"
	  echo $TIME
	fi
	((index+=1))
done

# rm -rf ./outfile/*

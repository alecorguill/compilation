#!/bin/bash


../.././parse test_$1.c | grep "syntax error" | uniq > $1.txt
if [ "`diff -w -s correct.txt $1.txt`" = "Les fichiers correct.txt et $1.txt sont identiques" ]
then
echo -e "test_$1 \033[32mOK\033[0m"
else
echo -e "test_$1 \033[31mKO\033[0m"
fi
rm $1.txt


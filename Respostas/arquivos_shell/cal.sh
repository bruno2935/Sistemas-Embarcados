#!/bin/bash
#echo $#                #informa o numero de argumentos da linha
#echo $@		     	   #mostra cade valor digitado na linha
aux=1
for p in $@
do
if [ $aux -eq 1 ]
then
concatenar=$p
aux=2
else
cal $concatenar  $p
aux=1
echo ---------------------------------------------
fi
done
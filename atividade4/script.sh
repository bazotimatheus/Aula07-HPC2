#!/bin/bash
# ====================================================
# Script para rodar a atividade 4 da aula 07
# Autor: Matheus Bazoti		Data:02/05/22
# ====================================================

echo "==========================================="
echo "                Atividade 4"
echo "==========================================="

mpicc -o quatro a4.c

for i in $(seq 2 4)
do

echo "Rodando com $i processo(s)"
mpirun -np $i ./quatro
echo ""

done

rm -fr quatro

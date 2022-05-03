#!/bin/bash
# ====================================================
# Script para rodar a atividade 3 da aula 07
# Autor: Matheus Bazoti		Data:02/05/22
# ====================================================

echo "==========================================="
echo "                Atividade 3"
echo "==========================================="

mpicc -o tres a3.c

for i in $(seq 1 4)
do

echo "Rodando com $i processo(s)"
mpirun -np $i ./tres
echo ""

done

rm -fr tres

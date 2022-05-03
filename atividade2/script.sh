#!/bin/bash
# ====================================================
# Script para rodar a atividade 2 da aula 07
# Autor: Matheus Bazoti		Data de entrega: 04/05/22
# ====================================================

echo "==========================================="
echo "                Atividade 2"
echo "==========================================="

mpicc -o dois a2.c

for i in $(seq 1 4)
do

echo "Rodando com $i processo(s)"
mpirun -np $i ./dois
echo ""

done

rm -fr dois

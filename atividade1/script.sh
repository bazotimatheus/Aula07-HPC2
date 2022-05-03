#!/bin/bash
# ====================================================
# Script para rodar a atividade 1 da aula 07
# Autor: Matheus Bazoti		Data de entrega: 04/05/22
# ====================================================

echo "==========================================="
echo "                Atividade 1"
echo "==========================================="

mpicc -o um a1.c

for i in $(seq 2 4)
do

echo "Rodando com $i processo(s)"
mpirun -np $i ./um
echo ""

done

rm -fr um

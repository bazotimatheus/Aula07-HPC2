#!/bin/bash
# ====================================================
# Script para rodar a atividade 5 da aula 07
# Autor: Matheus Bazoti		Data de entrega: 04/05/22
# ====================================================

# Para a atividade 5 o makefile irá compilar o código

echo "==========================================="
echo "             Atividade 5 (mpi)"
echo "==========================================="

make

for i in $(seq 1 4)
do

echo "Rodando com $i processo(s)"
time mpirun -np $i ./cinco
echo ""

done

make clean

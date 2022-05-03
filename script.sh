#!/bin/bash
# =========================================================
# Script para rodar as atividades da aula 07
# Aluno: Matheus Bazoti			Data: 02/05/22
# =========================================================

# Roda as atividades 1 até 4
for i in $(seq 1 1 4)
do
cd atividade$i
sh script.sh
cd ..
done

# Roda a atividade 5
cd atividade5

cd serial
sh script.sh
cd ..

cd mpi
sh script.sh
cd ../..

echo "\nAcabou!"
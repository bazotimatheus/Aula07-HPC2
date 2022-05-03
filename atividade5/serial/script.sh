#!/bin/bash
# ====================================================
# Script para rodar a atividade 5 da aula 07
# Autor: Matheus Bazoti		Data de entrega: 04/05/22
# ====================================================

echo "==========================================="
echo "           Atividade 5 (serial)"
echo "==========================================="

gcc a5-serial.c -o cinco-serial

time ./cinco-serial

echo ""

rm -fr cinco-serial
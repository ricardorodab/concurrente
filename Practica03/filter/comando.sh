#!/bin/bash
gcc -Wall -g -c filter.c -o filter.o && gcc main.c -o main.out filter.o

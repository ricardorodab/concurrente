#!/bin/bash

gcc -Wall -g -c petersen.c -o petersen.o && gcc main.c -o main.out petersen.o

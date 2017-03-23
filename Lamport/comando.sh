#!/bin/bash

gcc -Wall -g -c lamport.c -o lamport.o && gcc main.c -o main.out lamport.o

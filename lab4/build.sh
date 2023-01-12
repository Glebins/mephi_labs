#!/bin/bash

gcc -c mainm.c -o mainm.o -g
gcc -c funcs.c -o funcs.o -g
gcc funcs.o mainm.o -o mainm

gcc mainn.c -o mainn -lreadline -g

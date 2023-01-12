#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Letter
{
    char data;
    struct Letter *next;
} Letter;

typedef struct String
{
    Letter *head;
    Letter *tail;
} String;

String *new_string();
void delete_string(String *s);
int push_back(String *s, char l);
Letter *get_element(String *s, int n);
int insert_element(String *s, int n, char data);
int delete_element(String *s, int n);
int replace_element(String *s, int n, char data);
int get_length(String *s);
void print_string(String *s);
String *individual_work(String *str);
void sort(String *string, int start, int end, int (* comparator) (Letter *a, Letter *b));
int compare(const Letter *a, const Letter *b);

#endif

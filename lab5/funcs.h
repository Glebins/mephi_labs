#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <getopt.h>

typedef struct
{
    int id;
    char defcon;
    char *message;
} Page;

enum importance
{
    DEBUG = 0,
    INFO = 1,
    WARN = 2,
    ERROR = 3,
    FATAL = 4
};

Page new_page(int id, char defcon, char *text);
Page random_page(int a, int b);
void print_page(FILE *f, Page p);
void print_pages(FILE *f, Page *arr, int len);
void quick_sort(Page *arr, int len, int (* compare) (Page *, Page *));
void pair_insertion_sort(Page *arr, int len, int (* compare) (Page *, Page *));

int compare_id(const Page *p1, const Page *p2);
int compare_defcon(const Page *p1, const Page *p2);
int compare_message(const Page *p1, const Page *p2);
int incompare_id(const Page *p1, const Page *p2);
int incompare_defcon(const Page *p1, const Page *p2);
int incompare_message(const Page *p1, const Page *p2);

double get_time(int n);
char *get_str(FILE *f);
char *get_str1();
Page split(char *str);
char *substr(char *str, int start, int length);
char is_null_page(Page p);
Page get_null_page();

#endif

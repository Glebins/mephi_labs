#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

char lower(char c);
char *get_str();
char **split(char **arr, char *s, int *l);
void print_arr(char **arr, int l);
char is_anagrams(unsigned char *a, unsigned char *b);
char *delete_substr(char *str, int beg, int end);
int find(int *mas, int len, int element);

char *work(char **words, int len, char *s);

int my_strlen(char *str);
int my_strstr(char *text, char *str, int start);
char *my_strcat(char *s1, char *s2);
char *my_strcpy(char* s1, char *s2);

#endif

/* #include <stdio.h>
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

int compare_id(Page *p1, Page *p2);
int compare_defcon(Page *p1, Page *p2);
int compare_message(Page *p1, Page *p2);
int incompare_id(Page *p1, Page *p2);
int incompare_defcon(Page *p1, Page *p2);
int incompare_message(Page *p1, Page *p2);

double get_time(int n);
char *get_str(FILE *f);
char *get_str1();
Page split(char *str);
char *substr(char *str, int start, int length);
char is_null_page(Page p);
Page get_null_page(); */

#include "funcs.h"


Page split(char *str)
{
    int pos1 = -1;
    int pos2 = -1;

    // char *str1 = malloc(0);
    // char *str2 = malloc(0);
    // char *str3 = malloc(0);

    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == ';')
        {
            if (pos1 == -1) pos1 = i;
            else if (pos2 == -1) { pos2 = i;}
        }
    }

    if (pos1 == -1 || pos2 == -1) return get_null_page();

    // printf("%d %d\n", pos1, pos2);
    char *str1 = substr(str, 0, pos1);
    char *str2 = substr(str, pos1 + 2, pos2 - pos1 - 2);
    char *str3 = substr(str, pos2 + 2, strlen(str) - 1);

    int id = atoi(str1);
    char defcon;

    if (strcmp(str2, "debug") == 0) defcon = DEBUG;
    else if (!strcmp(str2, "info")) defcon = INFO;
    else if (!strcmp(str2, "warn")) defcon = WARN;
    else if (!strcmp(str2, "error")) defcon = ERROR;
    else if (!strcmp(str2, "fatal")) defcon = FATAL;
    else return get_null_page();

    Page p = new_page(id, defcon, str3);

    free(str1);
    free(str2);

    return p;
}

char is_null_page(Page p)
{
	if (p.id == -1 && p.defcon == -1 && !p.message)
		return 1;
	else return 0;
}

Page get_null_page()
{
	Page p = new_page(-1, -1, NULL);
	return p;
}

char* substr(char *str, int start, int length)
{
    char *s;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;

    if (length > 0)
    {
        if (start + length < len)
            len = start + length;
    }

    else len = len + length;

    int newlen = len - start + 1;

    s = (char *) malloc(newlen * sizeof(char));

    int j = 0;
    for (int i = start; i<len; i++)
    {
        s[j] = str[i]; j++;
    }
    s[j] = '\0';
    return(s);
}

char *get_str(FILE *f)
{
    char *ptr = (char *) malloc(1);
    const int BUFF_SIZE = 81;
    char buf[BUFF_SIZE];
    
    int n, len = 0;
    *ptr = '\0';

    do {
        n = fscanf(f, "%80[^\n]", buf);
        if (n < 0)
        {
            free(ptr);
            ptr = NULL;
            continue;
        }

        else if (n == 0) fscanf(f, "%*c");

        else
        {
            len += (int) strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strcat(ptr, buf);
        }
    } while (n > 0);

    return ptr;
}

/* double get_time(int n)
{
    double res_time = 0;

    for (int j = 0; j < 15; j++)
    {
        srand(time(NULL));

        int len = n;
        Page *arr = (Page *) malloc(0);

        for (int i = 0; i < len; i++)
        {
            arr = (Page *) realloc(arr, (i + 1) * sizeof(Page));
            arr[i] = random_page(1, n);
        }

        clock_t start = clock();

        // quick_sort(arr, len, (int (*) (const Page, const Page)) compare_id);
        // qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) compare_id);
        pair_insertion_sort(arr, len, (int (*) (const Page *, const Page *)) compare_id);

        clock_t end = clock();

        res_time += (double) (end - start) / CLOCKS_PER_SEC;

        free(arr);
    }

    return res_time / 15.0;
} */


void pair_insertion_sort(Page *arr, int len, int (* compare) (Page *, Page *))
{
    int left = 0;
    int right = len - 1;

    for (int k = left; ++left <= right; k = ++left)
    {
        Page a1 = arr[k], a2 = arr[left];

        if (compare(&a1, &a2) < 0)
        {
        	Page tmp = a2;
            a2 = a1;
            a1 = tmp;
        }

		if (k > 0)
		{
			while (compare(&a1, &arr[--k]) < 0)
			{
				arr[k + 2] = arr[k];
				if (k == 0) { k--; break; }
			}
		}
		else k--;

        arr[++k + 1] = a1;

        if (k > 0)
        {
        	while (compare(&a2, &arr[--k]) < 0)
        	{
        		arr[k + 1] = arr[k];
        		if (k == 0) { k--; break; }
        	}
        }
        else k--;

       arr[k + 1] = a2;
    }

    Page last = arr[right];

    if (right > 0)
    {
        while (compare(&last, &arr[--right]) < 0)
        {
        	arr[right + 1] = arr[right];
        	if (right == 0) { right--; break; }
        }
	}
    else right--;

    arr[right + 1] = last;
}

/* void pair(int *arr, int len, int (* compare) (int *, int *))
{
	int left = 0;
    int right = len - 1;

    for (int k = left; ++left <= right; k = ++left)
    {
    	printf("\n%d %d %d\n", k, left, right);
    	
        int a1 = arr[k];
        int a2 = arr[left];

        // if (compare(&a1, &a2) < 0)
        if (a1 < a2)
        {
        	int tmp = a2;
            a2 = a1;
            a1 = tmp;
        }

        // while (compare(&a1, &arr[--k]) < 0)
        if (k > 0)
        {
			while (a1 < arr[--k])
         	{
         		arr[k + 2] = arr[k];
         		if (k == 0) { k--; break; }
         	}
        }
        else k--;

        print(arr, len);

        arr[++k + 1] = a1;

        print(arr, len);

        // while (compare(&a2, &arr[--k]) < 0)
        if (k > 0)
        {
        	while (a2 < arr[--k])
        	{
        		arr[k + 1] = arr[k];
        		if (k == 0) { k--; break; }
        	}
        }
        else k--;

        print(arr, len);

       arr[k + 1] = a2;

       print(arr, len);
    }

    int last = arr[right];

    // while (compare(&last, &arr[--right]) < 0)
    if (right > 0)
    {
    	while (last < arr[--right])
    	{
    		arr[right + 1] = arr[right];
    		if (right == 0) { right--; break; }
    	}
    }
    else right--;

    arr[right + 1] = last;

    print(arr, len);
} */

void quick_sort(Page *arr, int len, int (* compare) (Page *, Page *))
{
    int i = 0;
    int j = len - 1;

    Page *mid = arr + len / 2;

    do {
    	while(compare(arr + i, mid) < 0)
        // while (compare(arr + i, mid) < 0)
            i++;

        while (compare(arr + j, mid) > 0)
            j--;

        if (i <= j)
        {
            Page tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
    {
        quick_sort(arr, j + 1, (int (*) (Page *, Page *)) compare);
    }

    if (i < len)
    {
        quick_sort(arr + i, len - i, (int (*) (Page *, Page *)) compare);
    }
}

int compare_id(const Page *p1, const Page *p2)
{
    return p1->id - p2->id;
}

int compare_defcon(const Page *p1, const Page *p2)
{
    return p1->defcon - p2->defcon;
}

int compare_message(const Page *p1, const Page *p2)
{
    return strcmp(p1->message, p2->message);
}

int incompare_id(const Page *p1, const Page *p2)
{
    return p2->id - p1->id;
}

int incompare_defcon(const Page *p1, const Page *p2)
{
    return p2->defcon - p1->defcon;
}

int incompare_message(const Page *p1, const Page *p2)
{
    return strcmp(p2->message, p1->message);
}

int comp(Page p1, Page p2)
{
    return p1.id - p2.id;
}

Page new_page(int id, char defcon, char *text)
{
    Page p = {id, defcon, text};

    return p;
}

Page random_page(int a, int b)
{
    int random_id = a + rand() % (b - a + 1);
    int random_defcon = rand() % 5;

    int ran_num = 3 + rand() % 55;
    char *random_str = (char *) malloc((ran_num + 1) * sizeof(char));

    for (int i = 0; i < ran_num; i++)
    {
    	int ran_ch = 33 + rand() % (122 - 33 + 1);
    	random_str[i] = ran_ch;
    }

    random_str[ran_num] = '\0';

    Page p = {random_id, random_defcon, random_str};

    return p;
}

void print_page(FILE *f, Page p)
{
    char *s = "";

    if (p.defcon == DEBUG) s = "debug";
    else if (p.defcon == INFO) s = "info";
    else if (p.defcon == WARN) s = "warn";
    else if (p.defcon == ERROR) s = "error";
    else if (p.defcon == FATAL) s = "fatal";

    fprintf(f, "%d; %s; %s\n", p.id, s, p.message);
}

void print_pages(FILE *f, Page *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        print_page(f, arr[i]);
    }
}

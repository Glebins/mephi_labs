#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <getopt.h>
#include "funcs.h"

/* typedef struct
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

int main(int argc, char *argv[])
{
	int rez = 0;
	char *type_of_sort = NULL, *field_of_sort = NULL, *direction_of_sort = NULL;
	
	while ((rez = getopt(argc, argv, "s:f:d:")) != -1)
	{
		if (rez == 's')
		{
			type_of_sort = optarg;
		}

		else if (rez == 'f')
		{
			field_of_sort = optarg;
		}

		else if (rez == 'd')
		{
			direction_of_sort = optarg;
		}
	}

	char *input_path = NULL, *output_path = NULL;

	if (argc > optind)
		input_path = argv[optind++];
		
	if (argc > optind)
		output_path = argv[optind];

	if (type_of_sort == NULL || field_of_sort == NULL || direction_of_sort == NULL ||
		input_path == NULL || output_path == NULL)
		{
			fprintf(stderr, "wrong number of params");
			return -1;
		}
	
    FILE *file_input, *file_output;

    Page *arr_pages = (Page *) malloc(0);
    int len_pages = 0;

    if ((file_input = fopen(input_path, "r")) == NULL)
    {
        fprintf(stderr, "The file not found\n");
        return -1;
    }

    while (feof(file_input) == 0)
    {
        char *s = get_str(file_input);

        if (s == NULL) { free(s); break; }

        Page p = split(s);
        free(s);
        
        if (is_null_page(p))
        {
            fprintf(stderr, "Wrong format file\n");
            continue;
        }

        len_pages++;
        arr_pages = (Page *) realloc(arr_pages, len_pages * sizeof(Page));
        arr_pages[len_pages - 1] = p;
    }

    print_pages(stdout, arr_pages, len_pages);
    printf("\n\n");

    if (!strcmp(type_of_sort, "quick") && !strcmp(field_of_sort, "id")
    		&& !strcmp(direction_of_sort, "1"))
    		quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_id);

    else if (!strcmp(type_of_sort, "quick") && !strcmp(field_of_sort, "id")
        	&& !strcmp(direction_of_sort, "0"))
        	quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_id);
        	
    else if (!strcmp(type_of_sort, "quick") && !strcmp(field_of_sort, "defcon")
        	&& !strcmp(direction_of_sort, "1"))
        	quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_defcon);

	else if (!strcmp(type_of_sort, "quick") && !strcmp(field_of_sort, "defcon")
        	&& !strcmp(direction_of_sort, "0"))
        	quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_defcon);  

	else if (!strcmp(type_of_sort, "quick") && !strcmp(field_of_sort, "message")
        	&& !strcmp(direction_of_sort, "1"))
        	quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_message);

	else if (!strcmp(type_of_sort, "quick") && !strcmp(field_of_sort, "message")
        	&& !strcmp(direction_of_sort, "0"))
        	quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_message);


	else if (!strcmp(type_of_sort, "insertion") && !strcmp(field_of_sort, "id")
    		&& !strcmp(direction_of_sort, "1"))
    		pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_id);

    else if (!strcmp(type_of_sort, "insertion") && !strcmp(field_of_sort, "id")
        	&& !strcmp(direction_of_sort, "0"))
        	pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_id);
        	
    else if (!strcmp(type_of_sort, "insertion") && !strcmp(field_of_sort, "defcon")
        	&& !strcmp(direction_of_sort, "1"))
        	pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_defcon);

	else if (!strcmp(type_of_sort, "insertion") && !strcmp(field_of_sort, "defcon")
        	&& !strcmp(direction_of_sort, "0"))
        	pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_defcon);  

	else if (!strcmp(type_of_sort, "insertion") && !strcmp(field_of_sort, "message")
        	&& !strcmp(direction_of_sort, "1"))
        	pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_message);

	else if (!strcmp(type_of_sort, "insertion") && !strcmp(field_of_sort, "message")
        	&& !strcmp(direction_of_sort, "0"))
        	pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_message);  


	else if (!strcmp(type_of_sort, "q") && !strcmp(field_of_sort, "id")
    		&& !strcmp(direction_of_sort, "1"))
    		qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) compare_id);

    else if (!strcmp(type_of_sort, "q") && !strcmp(field_of_sort, "id")
        	&& !strcmp(direction_of_sort, "0"))
        	qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) incompare_id);
        	
    else if (!strcmp(type_of_sort, "q") && !strcmp(field_of_sort, "defcon")
        	&& !strcmp(direction_of_sort, "1"))
        	qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) compare_defcon);

	else if (!strcmp(type_of_sort, "q") && !strcmp(field_of_sort, "defcon")
        	&& !strcmp(direction_of_sort, "0"))
        	qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) incompare_defcon);

	else if (!strcmp(type_of_sort, "q") && !strcmp(field_of_sort, "message")
        	&& !strcmp(direction_of_sort, "1"))
        	qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) compare_message);

	else if (!strcmp(type_of_sort, "q") && !strcmp(field_of_sort, "message")
        	&& !strcmp(direction_of_sort, "0"))
        	qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) incompare_message);

    else
    {
    	fprintf(stderr, "wrong params\n");
    }
    // qsort(arr_pages, len_pages, sizeof(Page), (int (*) (const void *, const void *)) incompare_id);
    // quick_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) incompare_id);
    // pair_insertion_sort(arr_pages, len_pages, (int (*) (Page *, Page *)) compare_message);

    print_pages(stdout, arr_pages, len_pages);

    if ((file_output = fopen(output_path, "w")) == NULL)
    {
    	fprintf(stderr, "Error open file\n");
    	return -1;
    }
    
    print_pages(file_output, arr_pages, len_pages);

    for (int i = 0; i < len_pages; i++)
    	free(arr_pages[i].message);

    free(arr_pages);
    fclose(file_input);
    fclose(file_output);

    printf("\n\n");

    return 0;
}

// print_pages(arr, len);
// qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) compare_id);
// quick_sort(arr, len, (int (*) (const Page, const Page)) compare_id);
// pair_insertion_sort(arr, len, (int (*) (const Page, const Page)) compare_id);
// print_pages(arr, len);




/* Page split(char *str)
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

    if (strcmp(str2, "debug") == 0) defcon = 0;
    else if (!strcmp(str2, "info")) defcon = 1;
    else if (!strcmp(str2, "warn")) defcon = 2;
    else if (!strcmp(str2, "error")) defcon = 3;
    else if (!strcmp(str2, "fatal")) defcon = 4;
    else return get_null_page();

    Page p = new_page(id, defcon, str3);

    free(str1);
    free(str2);

    return p;
}

char is_null_page(Page p)
{
	if (p.id == -1 && p.defcon == -1 && strcmp(p.message, "-1") == 0)
		return 1;
	else return 0;
}

Page get_null_page()
{
	Page p = new_page(-1, -1, "-1");
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

int compare_id(Page *p1, Page *p2)
{
    return p1->id - p2->id;
}

int compare_defcon(Page *p1, Page *p2)
{
    return p1->defcon - p2->defcon;
}

int compare_message(Page *p1, Page *p2)
{
    return strcmp(p1->message, p2->message);
}

int incompare_id(Page *p1, Page *p2)
{
    return p2->id - p1->id;
}

int incompare_defcon(Page *p1, Page *p2)
{
    return p2->defcon - p1->defcon;
}

int incompare_message(Page *p1, Page *p2)
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

    Page p = {random_id, 1, "msg"};

    return p;
}

void print_page(FILE *f, Page p)
{
    char *s = "";

    if (p.defcon == 0) s = "debug";
    else if (p.defcon == 1) s = "info";
    else if (p.defcon == 2) s = "warn";
    else if (p.defcon == 3) s = "error";
    else if (p.defcon == 4) s = "fatal";

    fprintf(f, "%d; %s; %s\n", p.id, s, p.message);
}

void print_pages(FILE *f, Page *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        print_page(f, arr[i]);
    }
}
*/

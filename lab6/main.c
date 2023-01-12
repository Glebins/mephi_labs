#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"

/* typedef struct Letter
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
int compare(const Letter *a, const Letter *b); */

int main()
{
    int input;
    int prev_input = -1;

    while ((input = getchar()) != EOF)
    {
    	String *string = new_string();
    	
    	while (input != '\n')
        {
            if (input == '\t') input = ' ';
            if (input == 32 && prev_input == 32)
            {
            	if ((input = getchar()) == EOF) break;
            	continue;
            }
            
            push_back(string, input);
            prev_input = input;
            input = getchar();
        }

        printf("\n");
        
        string = individual_work(string);
        print_string(string);

        printf("\n");
        delete_string(string);
    }

    
    // push_back(string, 65);
    // replace_element(string, 2, 65);
    // sort(string, 3, get_length(string) - 1, (int (*) (Letter *, Letter *)) compare);

    // printf("\n-%d-\n", get_length(string));

    // print_string(string);
    // printf("\n\n");

    // delete_string(string);

    return 0;
}



/* String *individual_work(String *str)
{
    // int n = get_length(str);
    Letter *ptr = str->head;
    int start = 0, end = 0, i = 0;

    while (ptr)
    {
    	if (ptr -> data == ' ')
    	{
    		end = i;
    		sort(str, start, end - 1, (int (*) (Letter *, Letter *)) compare);
    		
    		start = i;
    	}
    	
    	ptr = ptr->next;
    	i++;
    }

	end = i;
    sort(str, start, end - 1, (int (*) (Letter *, Letter *)) compare);

    return str;
}

void sort(String *string, int start, int end, int (* comparator) (Letter *a, Letter *b))
{
    for (int i = start; i < end; i++)
    {
        for (int j = start; j < end; j++)
        {
            Letter a = *get_element(string, j);
            Letter b = *get_element(string, j + 1);

            if (comparator(&a, &b) > 0)
            {
                Letter tmp = a;
                replace_element(string, j, b.data);
                replace_element(string, j + 1, tmp.data);
            }
        }
    }
}

int insert_element(String *s, int n, char data)
{
    int N = get_length(s);
    if (n >= N) return push_back(s, data);

    Letter *l1 = get_element(s, n);
    Letter *new = (Letter *) calloc(1, sizeof(Letter));

    if (!l1 || !new) return -1;

    new->next = l1;
    new->data = data;

    if (n > 0)
    {
        Letter *l2 = get_element(s, n - 1);
        l2->next = new;
    }

    else if (n == 0)
    {
        s->head = new;
    }

    else return -1;

    return n;
}

int delete_element(String *s, int n)
{
    int N = get_length(s);
    if (n >= N) n = N - 1;
    Letter *l1 = get_element(s, n);

    if (!l1) return -1;

    if (l1 == s->head)
        s->head = l1->next;

    else
    {
        Letter *l2 = get_element(s, n - 1);
        l2->next = l1->next;

        if (l1 == s->tail)
            s->tail = l2;
    }

    free(l1);

    return n;
}

int get_length(String *s)
{
    int n = 0;
    Letter *ptr = s->head;

    while (ptr != NULL)
    {
        ptr = ptr->next;
        n++;
    }

    return n;
}

int replace_element(String *s, int n, char data)
{
    int i1 = delete_element(s, n);
    int i2 = insert_element(s, n, data);

    return (i1 == -1 || i2 == -1) ? -1 : 0;
}

int compare(const Letter *a, const Letter *b)
{
    return a->data - b->data;
}

Letter *get_element(String *s, int n)
{
    Letter *ptr = s->head;

    for (int i = 0; i < n; i++)
    {
        if (!ptr) return NULL;
        ptr = ptr->next;
    }

    return ptr;
}

String *new_string()
{
    return (String *) calloc(1, sizeof(String));
}

void delete_string(String *s)
{
    Letter *ptr = s->head, *ptr_prev;

    while (ptr != NULL)
    {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }

    free(s);
}

int push_back(String *s, char l)
{
    Letter *new_l = (Letter *) malloc(sizeof(Letter));

    if (!new_l) return -1;

    new_l->next = NULL;
    new_l->data = l;

    if (!s->head)
    {
        s->head = new_l;
        s->tail = new_l;
    }

    else
    {
        s->tail->next = new_l;
        s->tail = new_l;
    }

    return 0;
}

void print_string(String *s)
{
    Letter *ptr = s->head, *ptr_prev;

    while (ptr != NULL)
    {
        ptr_prev = ptr;
        ptr = ptr->next;
        printf("%c", ptr_prev->data);
    }
} */

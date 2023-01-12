#include <stdlib.h>
#include <stdio.h>
#include "funcs.h"

int check_int(int is, int decision, int a, int b)
{
	if (is != 1 || decision < a || decision > b)
	{
		fprintf(stderr, "Input error\n");
	    scanf("%*c");
	    return -1;
	}

	return decision;
}



double **do_task(double **arr, int *length1, int *length2, int *res_len)
{
    int len1 = *length1;
    int len2 = *length2;

    int counter = 0;
    int current_position = 0;

    for (int i = 0; i < len1; i++)
    {
        if (find_element(arr[2], counter, arr[0][current_position], 0) == -1)
        {
           arr[2] = (double *) realloc(arr[2], (counter + 1) * sizeof(double));

            arr[2][counter] = arr[0][current_position];

            arr = delete_el_mat(arr, length1, current_position, 0);

            // arr[0] = (double *) realloc(arr[0], (*length1) * sizeof(double));

            counter++;
        }

        else
            current_position++;
    }

    current_position = 0;

    for (int i = 0; i < len2; i++)
    {
        if (find_element(arr[2], counter, arr[1][current_position], 0) == -1)
        {
            arr[2] = (double *) realloc(arr[2], (counter + 1) * sizeof(double));

            arr[2][counter] = arr[1][current_position];

            arr = delete_el_mat(arr, length2, current_position, 1);

            // arr[1] = (double *) realloc(arr[1], (*length2) * sizeof(double));

            counter++;
        }

        else
            current_position++;
    }

    *res_len = counter;

    return arr;
}

void *initialize(double *vector, int length)
{	
	for (int i = 0; i < length; i++)
			    {
			        printf("array[%d] =", i);
			        int is_err = scanf("%lf", &vector[i]);
			        
			        if (is_err != 1)
			        {
			        	fprintf(stderr, "Input error\n");
			        	return NULL;
			        }
			    }

    return vector;
}

void *insert_element(double *vector, int length, int index, double value)
{
    vector = realloc(vector, (length + 1) * sizeof(double));

    if (index >= length)
        vector[length] = value;

    else
    {
        for (int i = length - 1; i >= index; i--)
        {
            vector[i + 1] = vector[i];
            vector[i] = -999;
        }

        vector[index] = value;
    }

    return vector;
}


void *delete_element(double *vector, int *length, int index)
{
    if (index >= *length)
        index = (*length) - 1;

    for (int i = index; i <= *length - 2; i++)
    {
        vector[i] = vector[i + 1];
    }

    vector = (double *) realloc(vector, (*length - 1) * sizeof(double));

    (*length)--;
    
    return vector;
}

double **delete_el_mat(double **vector, int *length, int index, int n)
{
    if (index >= *length)
        index = (*length) - 1;

    for (int i = index; i <= *length - 2; i++)
    {
        vector[n][i] = vector[n][i + 1];
    }

    vector[n] = (double *) realloc(vector[n], (*length - 1) * sizeof(double));

    (*length)--;
    
    return vector;
}


void *work(double *mas, int *length, int number_array)
{
    int decision;
    printf("%d array:\n", number_array);

    do {
        decision = start_1();
    } while (decision == -1);

    if (decision == 1)
    {
        printf("Enter length of the array: ");
        scanf("%d", length);

        mas = (double *) realloc(mas, sizeof(double) * (*length));

        mas = (double *) initialize(mas, *length);
    }

    else if (decision == 2)
    {
        int position;
        double value;

        printf("Enter position: ");
        scanf("%d", &position);
        printf("Enter value: ");
        scanf("%lf", &value);

        mas = (double *) insert_element(mas, *length, position, value);
        (*length)++;
    }

    else if (decision == 3)
    {
        int position;

        printf("Enter position: ");
        scanf("%d", &position);

        mas = (double *) delete_element(mas, length, position);
    }

    else if (decision == 4)
        print_vector(mas, *length);

    return mas;
}




int start_0()
{
    printf("\n1 - Work with 1st array\n");
    printf("2 - Work with 2nd array\n");
    printf("3 - Do task completion\n");
    printf("4 - Exit\n");
    printf("Your choice: \n");

    int decision;
    int is_norm_input = scanf("%d", &decision); 

    if (check_int(is_norm_input, 1, 4,))

    return decision;
}

int start_1()
{
    printf("1 - Initialize array\n");
    printf("2 - Insert value\n");
    printf("3 - Delete value\n");
    printf("4 - Print array\n");
    printf("Your choice: \n");

    int decision;
    int is_norm_input = scanf("%d", &decision);

    if (is_norm_input != 1 || decision > 4 || decision < 1)
    {
        fprintf(stderr, "Input error\n");
        scanf("%*c");
        return -1;
    }

    return decision;
}


int find_element(double *array, double length, double element, int start)
{
    int pos = -1;

    for (int i = start; i < length; i++)
    {
        if (array[i] == element)
            pos = i;
    }

    return pos;
}

void print_vector(double *vector, int length)
{
	printf("Length = %d\n", length);
    for (int i = 0; i < length; i++)
    {
        printf("arr[%d] = %lf\n", i, vector[i]);
    }
}

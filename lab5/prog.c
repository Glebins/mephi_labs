#include "funcs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

double get_time_quick(int n_elements, int n_arrays, char *field, char *direct);
double get_time_pair(int n_elements, int n_arrays, char *field, char *direct);
double get_time_q(int n_elements, int n_arrays, char *field, char *direct);

int main(int argc, char *argv[])
{
	int rez = 0;
	char *type_of_sort = NULL, *field_of_sort = NULL, *direction_of_sort = NULL;
	char debug = 0;

	while ((rez = getopt(argc, argv, "s:f:d:o")) != -1)
	{
		if (rez == 's')
			type_of_sort = optarg;

		else if (rez == 'f')
			field_of_sort = optarg;

		else if (rez == 'd')
			direction_of_sort = optarg;

		else if (rez == 'o')
			debug = 1;
	}

	char *output_path = NULL, *num_elems = NULL, *num_arrays = NULL;

	if (argc > optind)
		output_path = argv[optind++];

	if (argc > optind)
		num_elems = argv[optind++];
		
	if (argc > optind)
		num_arrays = argv[optind];

	if (type_of_sort == NULL || field_of_sort == NULL || direction_of_sort == NULL ||
		output_path == NULL || num_elems == NULL || num_arrays == NULL)
		{
			fprintf(stderr, "wrong number of parametrs");
			printf("\n\n");
			return -1;
		}

	printf("\nnum_elems = %d\n", atoi(num_elems));

	FILE *file_output = fopen(output_path, "w");

	if (debug == 1)
	{
		printf("Debug\n");
		
		if (!strcmp(type_of_sort, "quick"))
		{
			for (int i = 500; i <= atoi(num_elems); i += 500)
			{
				double t = get_time_quick(i, atoi(num_arrays), field_of_sort, direction_of_sort);
				printf("%d --- %f\n", i, t);
				fprintf(file_output, "%d; %f\n", i, t);
			}
		}
	
		else if (!strcmp(type_of_sort, "pair"))
		{
			for (int i = 500; i <= atoi(num_elems); i += 500)
			{
				double t = get_time_pair(i, atoi(num_arrays), field_of_sort, direction_of_sort);
				printf("%d --- %f\n", i, t);
				fprintf(file_output, "%d; %f\n", i, t);
			}
		}
	
		else if (!strcmp(type_of_sort, "q"))
		{
			for (int i = 500; i <= atoi(num_elems); i += 500)
			{
				double t = get_time_q(i, atoi(num_arrays), field_of_sort, direction_of_sort);
				printf("%d --- %f\n", i, t);
				fprintf(file_output, "%d; %f\n", i, t);
			}
		}
	
		else
		{
			fprintf(stderr, "Wrong type of sort");
			return -1;
		}
	}

	else if (debug == 0)
	{
		printf("Not debug\n");
		
		if (!strcmp(type_of_sort, "quick"))
		{
			double t = get_time_quick(atoi(num_elems), atoi(num_arrays),
			field_of_sort, direction_of_sort);
			printf("--- %f --- \n", t);
		}
		
		else if (!strcmp(type_of_sort, "pair"))
		{
			double t = get_time_pair(atoi(num_elems), atoi(num_arrays),
			field_of_sort, direction_of_sort);
			printf("--- %f --- \n", t);
		}

		else if (!strcmp(type_of_sort, "q"))
		{
			double t = get_time_q(atoi(num_elems), atoi(num_arrays),
			field_of_sort, direction_of_sort);
			printf("--- %f --- \n", t);
		}
	}

	printf("\n\n");
	return 0;
}



double get_time_quick(int n_elements, int n_arrays, char *field, char *direct)
{
	double res_time = 0;

	for (int j = 0; j < n_arrays; j++)
	{
		srand(time(NULL));

		int len = n_elements;
		Page *arr = (Page *) malloc(0);

		for (int i = 0; i < len; i++)
		{
			arr = (Page *) realloc(arr, (i + 1) * sizeof(Page));
			arr[i] = random_page(1, n_elements);
		}

		clock_t start = clock();

		if (!strcmp(field, "id") && !strcmp(direct, "1"))
			quick_sort(arr, len, (int (*) (Page *, Page *)) compare_id);

		else if (!strcmp(field, "id") && !strcmp(direct, "0"))
			quick_sort(arr, len, (int (*) (Page *, Page *)) incompare_id);

		else if (!strcmp(field, "defcon") && !strcmp(direct, "1"))
			quick_sort(arr, len, (int (*) (Page *, Page *)) compare_defcon);

		else if (!strcmp(field, "defcon") && !strcmp(direct, "0"))
			quick_sort(arr, len, (int (*) (Page *, Page *)) incompare_defcon);

		else if (!strcmp(field, "message") && !strcmp(direct, "1"))
			quick_sort(arr, len, (int (*) (Page *, Page *)) compare_message);

		else if (!strcmp(field, "message") && !strcmp(direct, "0"))
			quick_sort(arr, len, (int (*) (Page *, Page *)) incompare_message);

		else
		{
			fprintf(stderr, "wrong parametrs");
			exit(-1);
		}

		clock_t end = clock();

		res_time += (double) (end - start) / CLOCKS_PER_SEC;

		free(arr);
	}

	return (double) res_time / n_arrays;
}

double get_time_pair(int n_elements, int n_arrays, char *field, char *direct)
{
	double res_time = 0;

	for (int j = 0; j < n_arrays; j++)
	{
		srand(time(NULL));

		int len = n_elements;
		Page *arr = (Page *) malloc(0);

		for (int i = 0; i < len; i++)
		{
			arr = (Page *) realloc(arr, (i + 1) * sizeof(Page));
			arr[i] = random_page(1, n_elements);
		}

		clock_t start = clock();

		if (!strcmp(field, "id") && !strcmp(direct, "1"))
			pair_insertion_sort(arr, len, (int (*) (Page *, Page *)) compare_id);

		else if (!strcmp(field, "id") && !strcmp(direct, "0"))
			pair_insertion_sort(arr, len, (int (*) (Page *, Page *)) incompare_id);

		else if (!strcmp(field, "defcon") && !strcmp(direct, "1"))
			pair_insertion_sort(arr, len, (int (*) (Page *, Page *)) compare_defcon);

		else if (!strcmp(field, "defcon") && !strcmp(direct, "0"))
			pair_insertion_sort(arr, len, (int (*) (Page *, Page *)) incompare_defcon);

		else if (!strcmp(field, "message") && !strcmp(direct, "1"))
			pair_insertion_sort(arr, len, (int (*) (Page *, Page *)) compare_message);

		else if (!strcmp(field, "message") && !strcmp(direct, "0"))
			pair_insertion_sort(arr, len, (int (*) (Page *, Page *)) incompare_message);

		else
				{
					fprintf(stderr, "wrong parametrs");
					exit(-1);
				}

		clock_t end = clock();

		res_time += (double) (end - start) / CLOCKS_PER_SEC;

		free(arr);
	}

	return (double) res_time / n_arrays;
}

double get_time_q(int n_elements, int n_arrays, char *field, char *direct)
{
	double res_time = 0;

	for (int j = 0; j < n_arrays; j++)
	{
		srand(time(NULL));

		int len = n_elements;
		Page *arr = (Page *) malloc(0);

		for (int i = 0; i < len; i++)
		{
			arr = (Page *) realloc(arr, (i + 1) * sizeof(Page));
			arr[i] = random_page(1, n_elements);
		}

		clock_t start = clock();

		if (!strcmp(field, "id") && !strcmp(direct, "1"))
			qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) compare_id);

		else if (!strcmp(field, "id") && !strcmp(direct, "0"))
			qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) incompare_id);

		else if (!strcmp(field, "defcon") && !strcmp(direct, "1"))
			qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) compare_defcon);

		else if (!strcmp(field, "defcon") && !strcmp(direct, "0"))
			qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) incompare_defcon);

		else if (!strcmp(field, "message") && !strcmp(direct, "1"))
			qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) compare_message);

		else if (!strcmp(field, "message") && !strcmp(direct, "0"))
			qsort(arr, len, sizeof(Page), (int (*) (const void *, const void *)) incompare_message);

		else
		{
			fprintf(stderr, "wrong parametrs");
			exit(-1);
		}

		clock_t end = clock();

		res_time += (double) (end - start) / CLOCKS_PER_SEC;

		free(arr);
	}

	return (double) res_time / n_arrays;
}

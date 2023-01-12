#ifndef LAB_3C_FUNCS_H
#define LAB_3C_FUNCS_H

void print_vector(double *vector, int length);
int find_element(double *array, double length, double element, int start);

int start_0();
int start_1();

void *work(double *mas, int *length, int number_array);

void *initialize(double *vector, int length);
void *insert_element(double *vector, int length, int index, double value);
void *delete_element(double *vector, int *length, int index);
double **delete_el_mat(double **vector, int *length, int index, int n);
double **do_task(double **arr, int *length1, int *length2, int *res_len);

#endif

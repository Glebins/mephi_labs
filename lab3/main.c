
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main()
{
    int decision_start;
    int length1 = 0;
    int length2 = 0;

    double **array = (double **) malloc(3 * sizeof(double *));

    array[0] = (double *) malloc(0);
    array[1] = (double *) malloc(0);
    
    do {
        do {
            decision_start = start_0();
        } while (decision_start == -1);

        if (decision_start == 1)
        {
            array[0] = work(array[0], &length1, 1);
        }

        else if (decision_start == 2)
        {
            array[1] = work(array[1], &length2, 2);
        }

        else if (decision_start == 3)
        {
			array[2] = (double *) malloc(0);
        
            int res_len = 0;

            array = do_task(array, &length1, &length2, &res_len);
            print_vector(array[2], res_len);
            print_vector(array[0], length1);
            print_vector(array[1], length2);

            free(array[2]);
        }

    } while (decision_start != 4);

    free(array[0]);
    free(array[1]);
    free(array);

    return 0;
}

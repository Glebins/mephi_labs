#include <stdio.h>
#include <math.h>
// #include <iostream>

// using namespace std;

double cos_1(double x, long n);
double cos_2(double x, double eps, int* n);
double abss(double x)
{
    if (x > 0) return x;
    else return -x;
}

int main()
{
    /* double x = 0;
    long n1 = 0;

    printf("Enter x:");
    int is_norm1 = scanf("%lf", &x);
    printf("Enter n:");
    int is_norm2 = scanf("%ld", &n1);
    printf("\n");

    if (!is_norm1 || !is_norm2) { printf("Incorect input"); return 0; }

    if  (n1 < 1) { printf("Incorect input"); return 0; }

    double res1 = cos_1(x, n1);
    double res2 = cos(x) * cos(x);
    printf("(cos x) ^ 2 = %lf\n", res1);
    printf("[math.h]: (cos x) ^ 2 = %lf", res2); */

    double x, eps;

    printf("Enter x:");
    int is_norm1 = scanf("%lf", &x);
    printf("Enter epsilon:");
    int is_norm2 = scanf("%lf", &eps);
    printf("\n");

    int n = 0;
    double res = cos_2(x, eps, &n);

    printf("Sum = %.20f\tn = %d\n", res, n);

    return 0;
}



double cos_1(double x, long n)
{
    double member = -x * x;
    double sum = 1 + member;

    if (n == 1) return 1;
    else if (n == 2) return sum;

    else
    {
        for (int i = 3; i <= n; i++)
        {
            member *= ((-4 * x * x) / ((2 * i - 3) * (2 * i - 2)));
            sum += member;

            // printf("a = %lf\tsum = %lf\n", member, sum);
        }
    }

    return sum;
}

double cos_2(double x, double eps, int *n)
{
    double member = -x * x;
    double sum = 1 + member;
    double sum_prev = 1;

    if (abss(abss(sum) - abss(sum_prev)) < eps)
    {
        *n = 2; return sum;
    }

    int i = 3;
    *n = 0;

    while (abss(abss(sum) - abss(sum_prev)) > eps)
    {
        sum_prev = sum;
        member *= ((-4 * x * x) / ((2 * i - 3) * (2 * i - 2)));
        sum += member;

        i++;
    }

    i--;

    *n = i;

    return sum;
}

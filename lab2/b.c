#include <stdio.h>
#include <math.h>

double cos_2(double x, double eps, int* n);
double abss(double x)
{
	if (x > 0) return x;
	else return -x;
}

int main()
{
	double x, eps;

	printf("Enter x:");
	int is_norm1 = scanf("%lf", &x);
	printf("Enter epsilon:");
	int is_norm2 = scanf("%lf", &eps);
	printf("\n");

	if (is_norm1 != 1 || is_norm2 != 1) { printf("Incorrect input"); return 0; }

	int n = 0;
	double res = cos_2(x, eps, &n);

	double right_cos = cos(x) * cos(x);

	printf("(cos x) ^ 2 = %.20f\nn = %d\n", res, n);
	printf("[math.h]: (cos x) ^ 2 = %.20f\n", right_cos);

	return 0;
}



double cos_2(double x, double eps, int* n)
{
	double member = -x * x;
	double sum = 1 + member;
	double sum_prev = 1;

	if (abss(abss(sum) - abss(sum_prev)) < eps)
	{
		*n = 2;
		return sum;
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

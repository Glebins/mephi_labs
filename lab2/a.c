#include <stdio.h>
#include <math.h>

double cos_1(double x, long n);
double abss(double x)
{
	if (x > 0) return x;
	else return -x;
}

int main()
{
	double x;
	long n;
	
	printf("Enter x:");
	int is_norm1 = scanf("%lf", &x);
	printf("Enter n:");
	int is_norm2 = scanf("%ld", &n);
	printf("\n");

	if (is_norm1 != 1 || is_norm2 != 1) { printf("Incorrect input"); return 0; }

	if (n < 1) { printf("Incorrect input"); return 0; }

	double res1 = cos_1(x, n);
	double res2 = cos(x) * cos(x);
	printf("(cos x) ^ 2 = %.20f\n", res1);
	printf("[math.h]: (cos x) ^ 2 = %.20f\n", res2);

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
		}
	}

	return sum;
}

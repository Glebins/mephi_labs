#include <stdio.h>


long long get_number_without_zeros(long long x, int* number_zeros);


int main()
{
	long long a;
	int number = 0;
	printf("Enter the number: ");
	scanf("%ld", &a);

	long long w = get_number_without_zeros(a, &number);

	printf("The number of zeros: %d\n", number);
	printf("The new number: %ld", w);

	return 0;
}


long long reverse(long long b)
{
	long long c = 0;
	while (b > 0)
	{
		c += b % 10;
		b /= 10;
		c *= 10;
	}
	
	c /= 10;

	return c;
}

long long get_number_without_zeros(long long x, int* number_zeros)
{
	*number_zeros = 0;
	int n = 0;  

	long long b = 0;
	long long c = 0;
	long long d = 1;

	if (x < 0)
	{
		d = x;
		x = -x;
	}
	
	while (x > 0)
	{
		char i = x % 10;

		if (i == 0)
		{
			n++;
		}

		else
		{
			b += i;
			b *= 10;
		}
		
		x /= 10;
	}

	b /= 10;

	c = reverse(b);
	
	if (d < 0)
	{
		c = -c;
	}

	*number_zeros = n;
	
	return c;
}

#include <stdio.h>

long long get_number_without_numbers(long long x, int* number_zeros);

int main()
{
  long long a;
  int number = 0;
  printf("Enter the number: ");
  scanf("ld", &a);
  
  long long w = get_number_without_zeros(a, &number);
}

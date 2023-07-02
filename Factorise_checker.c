#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * factorize - function that finds two numbers that are prime numbers of n
 * @n: interger
 */

void factorize(unsigned long n)
{
	unsigned long divisor = 2;
	int factor_found = 0;
	unsigned long factor = n / divisor;

	while (divisor * divisor <= n)
	{
		if (n % divisor == 0)
		{
			printf("%lu=%lu*%lu\n", n, factor, divisor);
			factor_found = 1;
			return;
		}

		if (divisor == 2)
			divisor++;
		else
			divisor += 2;

	}

	if (!factor_found)
	{
		printf("%lu=%lu*1\n", n, n);
	}
}

/**
 * main - code entry point
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: ...
 */
int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *file = fopen(filename, "r");
	int number;

	if (argc != 2)
	{
		printf("Usage: ./file <filename>\n");
		return (1);
	}

	if (file == NULL)
	{
		printf("Unable to open the file.\n");
		return (1);
	}

	while (fscanf(file, "%d", &number) == 1)
	{
		factorize(number);
	}

	fclose(file);
	return (0);
}

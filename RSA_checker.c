#include <stdio.h>
#include <stdlib.h>

/**
 * is_prime - ...
 * @n: ...
 *
 * Return: ...
 */
int is_prime(int n)
{
	int i = 0;

	if (n <= 1)
		return (0);

	for (i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
			return (0);
	}

	return (1);
}

/**
 * factorize - ...
 * @n: ...
 *
 * Return: ...
 */
void factorize(int n)
{
	int p = 2;
	int q = n / p;

	while (!is_prime(p) || !is_prime(q))
	{
		++p;
		q = n / p;
	}
	printf("%d=%d*%d", n, p, q);
}


/**
 * main - ...
 * @argc: ...
 * @argv: ...
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
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	if (file == NULL)
	{
		printf("Unable to open the file.\n");
		return (1);
	}

	if (fscanf(file, "%d", &number) != 1)
	{
		printf("Invalid number in the file.\n");
		fclose(file);
		return (1);
	}

	fclose(file);

	factorize(number);

	return (0);
}

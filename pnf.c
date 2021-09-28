#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	int* l = malloc(1600000*sizeof(l));
	_Bool p[100000];

	long long int n, g = 0, j = 100000, r = 0;
	int x = 100000, s;

	/*
	n - sequence number of the searched prime number
	l - array of prime numbers
	p - array of numbers to be checked
	g - count of prime numers
	j - count of all numbers
	r - result
	s - index that indicate where to continue
	*/

	p[0] = 0;
	p[1] = 0;
	for (int i = 2; i != x; i++) { p[i] = 1; }
	for (int i = 2; i < sqrt(x); i++)
	{
		if (p[i])
		{
			for (int o = i * i; o < x; o += i)
			{
				p[o] = 0;
			}
		}
	}
	for (int i = 0; i < j; i++)
	{
		if (p[i])
		{
			l[g] = i;
			g++;
		}
	}

	while (1)
	{
		if (g > 1600000)
		{
			g = 1600000;
			j = 25582153;
			r = 25582153;
		}
		printf("%s", "Enter sequence number: ");
		scanf("%I64d", &n);
		clock_t start = clock();

		if (n < g)
		{
			r = l[n - 1];
		}
		else
		{
			while (g < n)
			{
				for (int i = 0; i < x; i++) { p[i] = 1; }
				for (int i = 0; i < sqrt(g) / (g > 17000000 ? 2 : 1); i++)
				{
					s = l[i] - j % l[i] - 1;
					for (int o = s; o < x; o += l[i])
					{
						p[o] = 0;
					}
				}
				for (int i = 0; i < x; i++)
				{
					if (p[i])
					{
						if (g < 1600000)
						{
							l[g] = i + j + 1;
						}
						g++;
						if (g == n)
						{
							r = i + j + 1;
						}
					}
				}
				j += x;
				if (j % 1000000000 == 0 || (j - 25582153) % 1000000000 == 0)
				{
					system("cls");
					printf("%s %.3f%s %i%s %i%s", "progress:", (float)g * 100 / n, "%, time:", (int)((double)(clock() - start) / CLOCKS_PER_SEC), "s, left:", (int)((double)(clock() - start) / CLOCKS_PER_SEC * ((float)n / g - 1) * (1.45 - (float)g / n * 0.45)), "s");
				}
			}
		}

		char* a = "th";
		if (n % 10 == 1 && n % 100 != 11) { a = "st"; }
		if (n % 10 == 2 && n % 100 != 12) { a = "nd"; }
		if (n % 10 == 3 && n % 100 != 13) { a = "rd"; }
		system("cls");
		printf("%I64d%s %s %I64d%s%.3f%s\n", n, a, "prime number:", r, ", time: ", (double)(clock() - start) / CLOCKS_PER_SEC, "s");
	}
	return 0;
}

#include <stdio.h>          // printf(), putchar(), getc()
#include <string.h>         // memcpy()
#include <ctype.h>          // isdigit()

#define MAX_N 500000
#define SENTINEL 2000000000

const char NUL = '\0';
int l[MAX_N / 2 + 2], r[MAX_N / 2 + 2];
int count;

void
merge(int a[], int left, int mid, int right)
{
	int i, j, k;

	const int n1 = mid - left;
	const int n2 = right - mid;
	memcpy(l, &a[left], sizeof(int) * n1);
	memcpy(r, &a[mid], sizeof(int) * n2);
	l[n1] = SENTINEL, r[n2] = SENTINEL;

	i = 0, j = 0;
	for (k = left; k < right; ++k)
	{
		count++;
		if (l[i] <= r[j])
			a[k] = l[i++];
		else
			a[k] = r[j++];
	}
}

void
mergesort(int a[], int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid, right);
		merge(a, left, mid, right);
	}	
}

void
print_number(int n)
{
	char text[12];
	char* s = &text[11];
	*s = NUL;
	do
	{
		int m = n % 10;
		*--s = m + '0';
		n /= 10;
	} while (n != 0);

	printf("%s", s);
}

int
main(int argc, char** argv)
{
	int a[MAX_N];
	int n, m;
	int i;
	int c;

	c = getc(stdin);
	n = 0;
	while (isdigit(c))
	{
		n = n * 10 + c - '0';
		c = getc(stdin);
	}

	for (i = 0; i < n; ++i)
	{
		while (c == ' ' || c == '\n')
			c = getc(stdin);

		m = 0;
		while (isdigit(c))
		{
			m = m * 10 + c - '0';
			c = getc(stdin);
		}

		a[i] = m;
	}

	count = 0;
	mergesort(a, 0, n);

	for (i = 0; i < n; ++i)
	{
		print_number(a[i]);
		putchar((i != n - 1) ? ' ' : '\n');
	}

	printf("%d\n", count);
	return 0;
}

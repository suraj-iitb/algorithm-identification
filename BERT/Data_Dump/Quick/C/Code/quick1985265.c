#include <stdio.h>          // printf(), getc()
#include <ctype.h>          // isdigit()

#define MAX_N 100000
#define swap(x, y) { card_t t = x; x = y; y = t; }

typedef struct card_tbl
{
	char mark;
	int val;
	int seq;
} card_t;

card_t a[MAX_N];

int
partition(int p, int r)
{
	int j;

	int x = a[r].val;
	int i = p - 1;
	for (j = p; j < r; ++j)
	{
		if (a[j].val <= x)
		{
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[r]);
	return i + 1;
}

void
quicksort(int p, int r)
{
	if (p < r)
	{
		int q = partition(p, r);
		quicksort(p, q - 1);
		quicksort(q + 1, r);
	}
}

int
main(int argc, char** argv)
{
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

		a[i].mark = c;
		c = getc(stdin);
		while (c == ' ')
			c = getc(stdin);

		m = 0;
		while (isdigit(c))
		{
			m = m * 10 + c - '0';
			c = getc(stdin);
		}

		a[i].val = m;
		a[i].seq = i;
	}

	quicksort(0, n - 1);

	for (i = 0; i < n - 1; ++i)
	{
		if (a[i].val == a[i + 1].val && a[i].seq > a[i + 1].seq)
			break;
	}

	if (i >= n - 1)
		printf("Stable\n");
	else
		printf("Not stable\n");

	for (i = 0; i < n; ++i)
		printf("%c %d\n", a[i].mark, a[i].val);

	return 0;
}

#include <stdio.h>

int selection_sort(int n, int *a)
{
	int i, j, minj, x;
int ans = 0;

	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[minj]) minj = j;
		}
		if (i != minj) {
			x = a[i], a[i] = a[minj], a[minj] = x;
ans++;
		}
	}
return ans;
}

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

int a[102];

int main()
{
	int N, i, k;

	N = in();
	for (i = 0; i < N; i++) a[i] = in();
	k = selection_sort(N, a);
	printf("%d", a[0]);
	for (i = 1; i < N; i++) printf(" %d", a[i]);
	putchar('\n');
	printf("%d\n", k);
	return 0;
}


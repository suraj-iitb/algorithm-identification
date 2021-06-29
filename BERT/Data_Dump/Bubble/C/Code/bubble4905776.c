#include <stdio.h>

int bubble_sort(int n, int *a)
{
	int i, f, x;
int ans = 0;

	do {
		f = 0;
		for (i = n-1; i > 0; i--) {
			if (a[i] < a[i-1]) {
				x = a[i], a[i] = a[i-1], a[i-1] = x;
ans++;
				f = 1;
			}
		}
	} while (f);
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
	k = bubble_sort(N, a);
	printf("%d", a[0]);
	for (i = 1; i < N; i++) printf(" %d", a[i]);
	putchar('\n');
	printf("%d\n", k);
	return 0;
}

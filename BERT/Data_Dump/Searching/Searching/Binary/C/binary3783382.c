// id: ALDS1_4_B
#include <stdio.h>
#include <stdlib.h>

int bin_search(int a[], int n, int key);

int main(void)
{
	int n, q;
	int *s, *t;
	int cnt = 0;

	scanf("%d", &n);
	s = malloc(sizeof(int) * n);
	for ( int i = 0; i < n; ++i )
		scanf("%d", &s[i]);

	scanf("%d", &q);
	t = malloc(sizeof(int) * q);
	for ( int i = 0; i < q; ++i )
		scanf("%d", &t[i]);

	for ( int i = 0; i < q; ++i ) {
		if ( bin_search(s, n, t[i]) != -1 )
			++cnt;
	}

	printf("%d\n", cnt);

	free(s);
	free(t);

	return 0;
}

int bin_search(int a[], int n, int key)
{
	int left = 0, right = n - 1;
	int res = -1;

	while ( left <= right ) {
		int mid = (left + right) / 2;

		if ( a[mid] > key )
			right = mid - 1;
		else if ( a[mid] < key )
			left = mid + 1;
		else {
			res = mid;
			break;
		}
	}

	return res;
}

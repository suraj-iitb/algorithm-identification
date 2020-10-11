// id: ALDS1_2_B
#include <stdio.h>

#define MAX_N 100

int selection_sort(int a[], int n);

int main(void)
{
	int arr[MAX_N];
	int n, swap_times;

	scanf("%d", &n);
	for ( int i = 0; i < n; ++i )
		scanf("%d", &arr[i]);

	swap_times = selection_sort(arr, n);

	printf("%d", arr[0]);
	for ( int i = 1; i < n; ++i )
		printf(" %d", arr[i]);
	printf("\n");
	printf("%d\n", swap_times);

	return 0;
}

int selection_sort(int a[], int n)
{
	int cnt = 0;

	for ( int i = 0; i < n - 1; ++i ) {
		int minj = i;
		int minv = a[i];

		for ( int j = i + 1; j < n; ++j )
			if ( a[j] < minv ) {
				minv = a[j];
				minj = j;
			}

		if ( minj != i ) {
			a[minj] = a[i];
			a[i] = minv;
			++cnt;
		}
	}

	return cnt;
}

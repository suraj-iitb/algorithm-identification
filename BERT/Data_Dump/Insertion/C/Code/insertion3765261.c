// id: ALDS1_1_A
#include <stdio.h>

#define MAX_N 100

void print_array(int a[], int n);
void insertion_sort(int a[], int n);

int main(void)
{
	int n;
	int arr[MAX_N];

	scanf("%d", &n);
	for ( int i = 0; i < n; ++i )
		scanf("%d", &arr[i]);

	print_array(arr, n);
	insertion_sort(arr, n);

	return 0;
}

void print_array(int a[], int n)
{
	printf("%d", a[0]);

	for ( int i = 1; i < n; ++i )
		printf(" %d", a[i]);

	printf("\n");
}

void insertion_sort(int a[], int n)
{
	int tmp;
	int j;

	for ( int i = 1; i < n; ++i ) {
		tmp = a[i];

		for ( j = i; j > 0 && a[j - 1] > tmp; --j )
			a[j] = a[j - 1];

		a[j] = tmp;

		print_array(a, n);
	}
}

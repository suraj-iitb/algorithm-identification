#include <cstdio>

using namespace std;

void print(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		if (i > 0)	printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
}

void insertion_sort(int arr[], int n)
{
	int i, j, v;
	for (i = 1; i < n; i++) {
		v = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		print(arr, n);
	}
}

int main()
{
    int i, n, arr[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    print(arr, n);
    insertion_sort(arr, n);
    return 0;
}

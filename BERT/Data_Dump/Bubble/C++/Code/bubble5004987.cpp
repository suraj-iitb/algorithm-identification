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

int bubble_sort(int arr[], int n)
{
	int cnt;
	bool flag = 1;
	for (int i = 0; flag; i++){
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int i, j, n, cnt;
	int arr[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);

	cnt = bubble_sort(arr, n);
    print(arr, n);
	printf("%d\n", cnt);
	return 0;
}

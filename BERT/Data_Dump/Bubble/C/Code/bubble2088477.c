#include <stdio.h>

void BubbleSort(int array[], int len, int *count){

	int i, j;
	for (i = 0; i < len; i++) {
		for (j = len - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				int tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				(*count)++;
			}
		}
	}
}

int main()
{
	int n, i, count = 0;
	int num[100];
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d",&num[i]);
	}
	
	BubbleSort(num, n, &count);
	
	for (i = 0; i < n - 1; i++) {
		printf("%d ", num[i]);
	}
	printf("%d\n%d\n", num[n - 1], count);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000000
#define MIN_S 0
#define MAX_S 1000000000

int compare_cnt = 0;

void merge(int *array, int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int i, j, k, *left_array, *right_array;

	left_array = malloc(sizeof(int) * n1 + 100);
	right_array = malloc(sizeof(int) * n2 + 100);

	for(i = 0; i < n1; i++) 
		left_array[i] = array[left + i];
	for(i = 0; i < n2; i++)
		right_array[i] = array[mid + i];
	left_array[n1] = MAX_S + 1;
	right_array[n2] = MAX_S + 1;
	i = 0;
	j = 0;
	for(k = left; k < right; k++) {
		compare_cnt++;
		if(left_array[i] <= right_array[j]) 
			array[k] = left_array[i++];
		else 
			array[k] = right_array[j++];
		
	}
	free(left_array);
	free(right_array);
}

void merge_sort(int *array, int left, int right)
{
	if(left + 1 < right) {
		int mid;

		mid = (left + right) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid, right);
		merge(array, left, mid, right);
	}

}

int main(void)
{
	int i, n, *num;

	scanf("%d", &n);
	num = malloc(sizeof(int) * n + 100);
	for(i = 0; i < n; i++) {
		scanf("%d", num + i);
	}

	merge_sort(num, 0, n);

	for(i = 0; i < n - 1; i++) {
		printf("%d ", num[i]);
	}
	printf("%d\n", num[i]);
	printf("%d\n", compare_cnt);
	free(num);

	return 0;
}

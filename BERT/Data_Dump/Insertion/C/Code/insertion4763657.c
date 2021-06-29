#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void DispArr(int32_t arr[], int32_t len) {
	printf("%d", arr[0]);
	for (int32_t i = 1; i < len; i++) {
		printf(" %d", arr[i]);
	}
	putchar('\n');
}

void InsertionSort(int32_t arr[], int32_t len) {
	DispArr(arr, len);
	for (int32_t i = 1; i < len; i++) {
		int32_t target = arr[i];
		int32_t j = i - 1;
		for (; j >= 0 && arr[j] > target; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = target;
		DispArr(arr, len);
	}
}

int main() {
	int32_t dataNum;
	scanf("%d", &dataNum);

	int32_t *data = (int32_t *)calloc(dataNum, sizeof(int32_t));
	if (!data) return 1;

	for (int32_t i = 0; i < dataNum; i++) {
		scanf("%d", &data[i]);
	}
	
	InsertionSort(data, dataNum);
	return 0;
}


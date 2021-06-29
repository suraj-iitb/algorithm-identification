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

void Swap(int32_t *a, int32_t *b) {
	int32_t tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectionSort(int32_t arr[], int32_t len) {
	int32_t swapCnt = 0;
	for (int32_t i = 0; i < len; i++) {
		int32_t minPos = i;
		for (int32_t j = i+1; j < len; j++) {
			minPos = (arr[minPos] > arr[j]) ? j : minPos;
		}
		if (minPos != i) {
			Swap(&arr[i], &arr[minPos]);
			swapCnt++;
		}
	}
	DispArr(arr, len);
	printf("%d\n", swapCnt);
}

int main() {
	int32_t dataNum;
	scanf("%d", &dataNum);

	int32_t *data = (int32_t *)calloc(dataNum, sizeof(int32_t));
	if (!data) return 1;

	for (int32_t i = 0; i < dataNum; i++) {
		scanf("%d", &data[i]);
	}
	
	SelectionSort(data, dataNum);
	return 0;
}


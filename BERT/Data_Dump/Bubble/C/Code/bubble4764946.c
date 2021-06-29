#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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

void BubbleSort(int32_t arr[], int32_t len) {
	int32_t swapCnt = 0;
	bool needLoop = true;
	for (int32_t i = 0; needLoop; i++) {
		needLoop = false;
		for (int32_t j = len-1; j > i; j--) {
			if (arr[j-1] > arr[j]) {
				Swap(&arr[j-1], &arr[j]);
				swapCnt++;
				needLoop = true;
			}
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
	
	BubbleSort(data, dataNum);
	return 0;
}


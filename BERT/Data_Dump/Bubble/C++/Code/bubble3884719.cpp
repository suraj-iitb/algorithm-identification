#include <stdio.h>
#include <utility>

using namespace std;

#define ARRAY_SIZE_MAX 100

int main()
{
	int arraySize = 0;

	scanf("%d", &arraySize);

	int A[ARRAY_SIZE_MAX] = { 0 };
	for (int i = 0; i < arraySize; i++) {
		scanf("%d", &A[i]);
	}

	bool isSort = true;
	int sortedIndex = 0;
	int swapCount = 0;
	while (isSort) {
		isSort = false;
		for (int i = arraySize - 1; i > sortedIndex; i--) {
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
				isSort = true;
				swapCount++;
			}
		}

		sortedIndex++;
	}

	// 結果出力
	// ソート済み配列
	for (int i = 0; i < arraySize; i++) {
		if (i != arraySize - 1) {
			printf("%d ", A[i]);
		}
		else {
			printf("%d\n", A[i]);
		}
	}

	// 交換回数
	printf("%d\n", swapCount);


	return 0;
}

#include <stdio.h>
#include <utility>

using namespace std;

#define ARRAY_SIZE_MAX 100

int main()
{
	int arraySize = 0;

	scanf("%d", &arraySize);

	int Array[ARRAY_SIZE_MAX] = { 0 };
	for (int i = 0; i < arraySize; i++) {
		scanf("%d", &Array[i]);
	}

	int swapCount = 0;

	for (int i = 0; i < arraySize; i++) {
		int minIndex = i;

		for (int j = i + 1; j < arraySize; j++) {
			if (Array[minIndex] > Array[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			swap(Array[minIndex], Array[i]);
			swapCount++;
		}
	}



	// 結果出力
	// ソート済み配列
	for (int i = 0; i < arraySize; i++) {
		if (i != arraySize - 1) {
			printf("%d ", Array[i]);
		}
		else {
			printf("%d\n", Array[i]);
		}
	}

	// 交換回数
	printf("%d\n", swapCount);


	return 0;
}

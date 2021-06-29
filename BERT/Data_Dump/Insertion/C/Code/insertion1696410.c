#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printOut(int *numArray, int listNum)
{
	int i;
	for (i = 0; i < listNum; i++) {
		if (i == listNum - 1) {
			printf("%d\n", numArray[i]);
		}
		else {
			printf("%d ", numArray[i]);
		}
	}
}

void insertionSort(int *A, int N)
{
	int i;
	for (i = 1; i <= N - 1; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		printOut(A, N);

	}
}

int main(int argc, char** argv)
{
	int N, i;
	int numlist[100];

	memset(numlist, '\0', sizeof(numlist));

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &numlist[i]);
	}

	printOut(numlist, N);
	insertionSort(numlist, N);
	return 0;
}

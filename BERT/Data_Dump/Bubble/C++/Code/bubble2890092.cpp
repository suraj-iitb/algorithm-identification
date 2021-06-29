#include <stdio.h>
using namespace std;
int bubbleSort(int A[], int N) {
	int counter = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int j = N - 1; j > 0; j--) {
			if (A[j - 1] > A[j]) {
				int v = A[j];
				A[j] = A[j - 1];
				A[j - 1] = v;
				flag = true;
				counter++;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	return counter;
}
int main() {
	int N,i;
	int A[100];
	scanf("%d", &N);
	for (i = 0;i < N;i++)
		scanf("%d", &A[i]);
	printf("%d\n",bubbleSort(A, N));
}

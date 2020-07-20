#pragma warning(disable:4996)
#include<stdio.h>
void bubbleSort(int A[],int N) {
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j> i; j--) {//从数组末尾至i出遍历
			if (A[j] < A[j - 1]) {//若逆序，交换之
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				k++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", A[i]);
		
	}
	printf("\n%d\n", k);
}
int main() {
	int N,A[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	bubbleSort(A, N);
	
	return 0;
}

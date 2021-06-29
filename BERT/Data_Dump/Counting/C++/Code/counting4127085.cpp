#include <cstdio>

void CountingSort(int A[], int B[], int len, int maxNum)
{
	//选择排序算法中,　方便起见, 不使用index=0的位置 
	int C[maxNum+1];
	
	for (int i = 0; i <= maxNum; i++) {
		C[i] = 0;
	}
	for (int i = 1; i < len; i++) {
		C[A[i]]++;
	}
	for (int i = 1; i <= maxNum; i++) {
		C[i] += C[i-1];
	}
	
	//从A[]的末尾开始选择,　是为了保证算法的稳定性 
	for (int i = len-1; i >= 1; i--) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

int main(void)
{
	//选择排序算法中,　方便起见, 不使用index=0的位置 
	int n;
	int max = -999999999;
	
	scanf("%d", &n);
	int A[n+1];
	int B[n+1];
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		if (A[i] > max) {
			max = A[i];
		}
	}
	CountingSort(A, B, n+1, max);
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%d", B[i]);
	}
	printf("\n");
	
	
	return 0;
} 

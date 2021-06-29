#include <cstdio>

int A[2000000];
int B[2000000];

void countingSort(int n) {
	int C[10001];

	//初期化
	for (int i = 0;i < 10001; i++){
		C[i] = 0;
	}

	//カウントしてCに格納していく
	for (int i = 0; i < n; i++) {
		C[A[i]]++;
	}

	for (int i = 1; i < 10001; i++) {
		C[i] = C[i] + C[i-1];
	}

	for (int i = n-1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}

}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	
	countingSort(n);

	for (int i = 0; i < n - 1; i++) {
		printf("%d ", B[i]);
	}

	printf("%d\n", B[n-1]);
	return 0;
}

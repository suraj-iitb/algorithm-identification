#include<stdio.h>
void insertionSort(int A[], int N);
int main(void){
	int n[100];
	int i, r;
	scanf("%d", &i);
	for (r = 0; r < i; r++){
		scanf("%d", &n[r]);
	}
	for (r = 0; r < i; r++){
		if (r != i - 1){ printf("%d ", n[r]); }
		else{
			printf("%d\n", n[r]);
		}
	}
	insertionSort(n, i);

	return 0;
}
	void insertionSort(int A[], int N){
		int i, j, v, r;
		for (i = 1; i < N; i++){
			v = A[i];
			j = i - 1;
			while (j >= 0 && A[j] > v){
				A[j + 1] = A[j];
				j--;
				A[j + 1] = v;
			}
			for (r = 0; r < N; r++){
				if (r != N - 1){ printf("%d ", A[r]); }
				else{
					printf("%d\n", A[r]);
				}
			}

		}
		return;
	}

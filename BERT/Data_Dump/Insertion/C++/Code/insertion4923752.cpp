#include<cstdio>
using namespace std;

const int maxn = 110;

void trace(int A[], int N) {
	for (int t=0; t<N; t++) {
		if (t > 0) printf(" ");
		printf("%d", A[t]);
	}
	printf("\n");
} 

void insertionSort(int A[], int N) {
	for (int i=1; i<N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		trace(A, N);
	}
}

int main() {
	int A[maxn];
	
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", &A[i]);
	
	trace(A, N);
	insertionSort(A, N);
	return 0;
}

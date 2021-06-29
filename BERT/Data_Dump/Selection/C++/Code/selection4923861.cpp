#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;

void trace(int A[], int N) {
	for (int t=0; t<N; t++) {
		if (t > 0) printf(" ");
		printf("%d", A[t]);
	}
	printf("\n");
} 

int selectSort(int A[], int N) {
	int sw = 0;
	for (int i=0; i<N; i++) {
		int minj = i;
		for (int j=i+1; j<N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			swap(A[i], A[minj]);
			sw ++;	
		}
	}
	return sw;
}

int main() {
	int A[maxn];
	
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", &A[i]);
	
	int sw = selectSort(A, N);
	trace(A, N);
	printf("%d\n", sw);
	return 0;
}

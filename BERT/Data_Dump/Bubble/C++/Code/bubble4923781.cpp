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

int bubbleSort(int A[], int N) {
	int repeat = 0;
	bool flag = true;
	for (int i = 0; flag; i++) {
		flag = false;
		for (int j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j-1]) {
				repeat ++;
				swap(A[j], A[j-1]);
				flag = true;
			}
		}
	}
		
	return repeat;
}

int main() {
	int A[maxn];
	
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", &A[i]);
	
	int repeat = bubbleSort(A, N);
	trace(A, N);
	printf("%d\n", repeat);
	return 0;
}

#include <stdio.h>

using namespace std;

void data_print(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i>0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}
void sort(int A[], int N) {
	int i, j;
	for (i = 1; i < N; i++) {
		int v = A[i];
		j = i - 1;
		while ((A[j] > v) && j >= 0) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		data_print(A, N);
	}
}
int main()
{
	int N;
	int A[100];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	data_print(A, N);
	sort(A, N);

	return 0;
}

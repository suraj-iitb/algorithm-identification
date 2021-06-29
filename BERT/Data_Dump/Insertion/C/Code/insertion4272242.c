#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include <string.h>

void inserionSort(int A[], int N) {
	int i = 0;
	for (i = 1; i < N; i++) {
		int print_i = 0;
		for (; print_i < N; print_i++)
		{
			printf("%d", A[print_i]);
			if (print_i != N - 1) {
				printf(" ");
			}
		}
		printf("\n");

		int v = A[i];
		int j = i-1;
		while ( j>= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
}

int main(void) {

	//int result[1001] = { 0 };

	int n = 0;

	scanf("%d", &n);

	int A[1001] = { 0 };

	int i = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	

	inserionSort(A, n);
	
	for (i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if (i != n - 1) {
			printf(" ");
		}
		
	}
	printf("\n");
	

	return 0;
}





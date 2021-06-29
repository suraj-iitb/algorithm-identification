#include <iostream>
#include <stdio.h>

using namespace std;

void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0) printf(" ");
		printf("%d", A[i]); 	
	}
	printf("\n");
}

int bubbleSort(int A[], int N) {
	int flag = 1;
	int count = 0;

	while (flag) {
		flag = 0;

		for (int i = N - 1; i > 0; i--) {
			if (A[i] < A[i - 1]) {
				int tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				
				flag = 1;
				count++;
			}
		}

	}
	
	trace(A, N);

	return count;
}

int main() {
	int N;
	int A[100];
	int count;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	
	count = bubbleSort(A, N);			

	cout << count << endl;

	return 0;
}

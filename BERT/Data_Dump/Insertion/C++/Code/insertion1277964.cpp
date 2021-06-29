#include <iostream>
#include <cstdio>

using namespace std;

int A[1000];

void printArray (int N) {
	for (int i=0; i<N; i++) {
		// cout << A[i] << " ";
		printf("%d", A[i]);
		if (i==N-1) {
			printf("\n");
			// cout << endl;
		} else {
			printf(" ");
		}
	}
	return;
}

void insertionSort (int N) {
	printArray(N);
	for (int i=1; i<N; i++) {
		int v = A[i];
		int j = i -1;
		while (A[j] > v) {
			A[j+1] = A[j];
				j--;
		}
		A[j+1] = v;
		printArray(N);
	}
	return;
}

int main(int argc, char const* argv[])
{
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i];
	}
	insertionSort (N);
	
	return 0;
}

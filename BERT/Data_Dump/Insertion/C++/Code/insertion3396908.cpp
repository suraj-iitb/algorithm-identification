#include <iostream>
using namespace std;

void print(int* A, int N) {
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
}

void insertionSort(int* A, int N) {
	int v = 0, j = 0;
	for (int i = 0; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		print(A, N);
	}
}

int main()
{
	int i, j[100];
	cin >> i;
	int c=0, temp = i;
	while (temp--) {
		cin >> j[c++];
	}
	insertionSort(j, i);
    return 0;
}


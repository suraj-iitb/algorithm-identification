#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

template<typename T>
void swap(T *a, T *b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template<typename T>
void showArray(T A[], int N) {
	for (int i = 0; i < N - 1; i++) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
}

template<typename T>
void insertionSort(T A[], int N) {
	showArray<T>(A, N);
	for (int i = 1; i < N; i++) {
		int tmp = A[i];
		int j = i-1;
		while (j >= 0 && A[j] > tmp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
		showArray<T>(A, N);
	}
}



int main() {

	int N;
	int A[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", A+i);
	}

	insertionSort<int>(A, N);

	return 0;
}

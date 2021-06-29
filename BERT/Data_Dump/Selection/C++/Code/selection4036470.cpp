#include <iostream>
#include<string>
#include <cassert>
#include <algorithm>
#include <functional>
#include<stdio.h>

using namespace std;

//flagを用いたバブルソート
int selectionSort(int A[], int N) {
	int sw = 0;
	int tmp;
	int minj;
	int i;
	int j;
	for (i = 0; i < N-1; ++i) {
		 minj = i;
		 for (j = i; j < N; ++j) {
			 if (A[j] < A[minj]) {

				 minj = j;
			 }
		 }
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
				if (i != minj) {
					++sw;
				}
			
			

		}
		return sw;
	}
	
	



int main() {
	int A[100], N, sw;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];

	sw = selectionSort(A, N);

	for (int i = 0; i < N; ++i) {
		if (i)cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;

	return 0;
}

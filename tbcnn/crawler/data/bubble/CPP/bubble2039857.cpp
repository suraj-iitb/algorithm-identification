#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int BubbleSort(int A[],int N){
	bool flag=1;
	int i;
	int j;
	int sw=0;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = N - 1; j >= i+1; j--) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main() {
	int N;
	int A[100];
	int sw;
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> A[i]; }
	
	sw = BubbleSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i) { cout << " "; }
		cout << A[i];
	}
		cout << endl;
		cout << sw << endl;
	}

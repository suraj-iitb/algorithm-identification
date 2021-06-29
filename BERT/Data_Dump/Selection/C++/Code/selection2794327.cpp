//============================================================================
// Name        : AOJCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

void trace(int A[], int n) {
	for (int j = 0; j < n-1; j++) {
		cout << A[j] << " ";
	}

	cout << A[n-1] << endl;
}

int main() {
	int n;
	int A[MAX];
	int count = 0;

	cin >> n;

	for(int i=0; i < n; i++) {
		cin >> A[i];
	}

	for(int i = 0; i < n; i++) {
		int minj = i;
		for(int j = i; j < n; j++) {
			if(A[minj]>A[j]) {
				minj = j;
			}
		}
		if(minj!=i) {
			int tmp = A[minj];
			A[minj] = A[i];
			A[i] = tmp;
			count++;
		}

//		trace(A,n);
	}
	trace(A,n);
	cout << count << endl;

}




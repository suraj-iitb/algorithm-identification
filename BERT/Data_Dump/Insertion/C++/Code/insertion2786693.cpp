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

	cin >> n;

	for(int i=0; i < n; i++) {
		cin >> A[i];
	}
	trace(A,n);

	for(int i = 1; i < n; i++) {
		int v = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		trace(A, n);
	}
}




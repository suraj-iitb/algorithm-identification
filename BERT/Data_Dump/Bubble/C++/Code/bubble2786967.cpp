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

void trace(int A[], int n) {
	for (int j = 0; j < n-1; j++) {
		cout << A[j] << " ";
	}

	cout << A[n-1] << endl;
}

int main() {

	int n;


	cin >> n;
	int A[n];

	for(int i=0; i < n; i++) {
		cin >> A[i];
	}

	int count = 0;
	bool flag = 1;
	int j = 0;
	while(flag) {
		flag = 0;
		for(int i = n-1; i > j; i--) {
			if (A[i] < A[i-1]) {
				int tmp = A[i-1];
				A[i-1] = A[i];
				A[i] = tmp;
				flag = 1;
				count++;
			}
		}
		j++;
	}
	trace(A,n);
	cout << count << endl;
}


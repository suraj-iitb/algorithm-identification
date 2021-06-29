/*
 * main.cpp
 *
 *  Created on: 2020/07/21
 *      Author: 113896
 */

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> A, bool newline=true) {
	for (int i = 0; i < (int)A.size(); i++) {
		cout << A[i];
		if (i != (int)A.size()-1) cout << " ";
	}
	if (newline) {
		cout << endl;
	}
}

void insertionSort(vector<int> A) {
	for (int i = 1; i < (int)A.size(); i++) {
		printVector(A);
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
	printVector(A);
}

int main() {

	int N;
	cin >> N;
	vector<int> data(N);
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		data[i] = tmp;
	}

	insertionSort(data);

	return 0;
}




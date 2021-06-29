#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cmath>
using namespace std;

void insertionSort(int* A, int N) {
	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (int i = 0; i < N-1; i++) {
			cout << A[i] << " ";
		}
		cout << A[N - 1] << endl;
	}
}


int main() {
	int length, elem[1000];
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> elem[i];
	}
	for (int i = 0; i < length -1; i++) {
		cout << elem[i] << " ";
	}
	cout << elem[length - 1] << endl;

	insertionSort(elem, length);


}

#include <iostream>
using namespace std;

void display(int array[], int length) {
	for (int i = 0; i < length-1; i++) {
		cout << array[i] << " ";
	}

	cout << array[length-1] << endl;
}

void insertion_sort(int A[], int length) {
	for (int j = 1; j < length; j++) {
		display(A, length);
		int key = A[j];
		int i = j -1;
		// Insert key into the sorted array A[1...j-1]
		while (i >= 0 && A[i] > key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
	display(A, length);
}

int main() {
	int length;
	cin >> length;
	int array[length];
	
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}

	insertion_sort(array, length);

	return 0;
}

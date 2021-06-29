#include <iostream>
using namespace std;

void printArray(int A[], int n, int count) {
	for (int i{ 0 }; i != n; i++) {
		if (i != 0)cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int selectionSort(int A[], int n) {
	int count = 0;

	for (int i{ 0 }; i < n; i++) {
		int mini = i;
		for (int j = i; j < n; j++) {
			if (A[mini] > A[j]) {
				swap(mini,j);
			}
		}

		if (mini != i) count++;
		swap(A[i], A[mini]);
	}
	return count;
}

int main()
{
	int n;
	int a[100];
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		cin >> a[i];
	}
	int count = selectionSort(a, n);
	printArray(a, n, count);
	return 0;
}

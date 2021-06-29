#include<iostream>
using namespace std;

void display(int n, int* A) {
	for (int i = 0; i < n-1; i++) {
		cout << A[i] << " ";
	}
	cout << A[n-1] << endl;
}

int main() {
	int n;
	cin >> n;
	int* A=new int[n];
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	display(n, A);

	for (int i = 1; i < n; i++) {
		temp = A[i];
		int j = i - 1;
		while (j >= 0 && temp < A[j]) {
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = temp;
		display(n, A);
	}

	
	return 0;
}


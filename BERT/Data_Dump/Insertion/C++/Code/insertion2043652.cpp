#include<iostream>
using namespace std;
static const int MAX = 100;

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << (i != n - 1 ? " " : "");
	}
	cout << endl;
}


int main()
{
	int n;
	int A[MAX];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	printArray(A, n);
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
		printArray(A, n);
	}


    return 0;
}

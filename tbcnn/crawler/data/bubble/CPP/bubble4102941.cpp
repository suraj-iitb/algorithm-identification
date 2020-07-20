#include<iostream>
#include<stdio.h>
using namespace std;

int bubble(int A[], int n)
{
	int sw=0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}

int main()
{
	int i, n, A[100],sw;

	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &A[i]);

	sw = bubble(A, n);

	for (i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl << sw << endl;

	
}

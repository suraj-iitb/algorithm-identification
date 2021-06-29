#include<iostream>
#include<cstdio>
#define N 1000
using namespace std;

void selectionSort(int n, int A[]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i + 1; j < n; j++) {
			if (A[minj] > A[j]) {
				minj = j;
			}
		}
		int t = A[i];
		A[i] = A[minj];
		A[minj] = t;
		if(i != minj ) count++;
	}
	for (int i = 0; i < n; i++) {
		if(i != 0) cout << " " << A[i];
		else cout << A[i];
	}
	cout << endl << count << endl;
}

int main() {
	int n;
	int A[N];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	selectionSort(n, A);

	return 0;
}

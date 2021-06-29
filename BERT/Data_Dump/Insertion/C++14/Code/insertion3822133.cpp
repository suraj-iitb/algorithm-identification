#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int N) {
	int v, j;
	for (int i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
		for (int z = 0; z < N-1; z++) {
			cout << A[z] << " ";
		}
		cout << A[N - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N; cin >> N;
	int a[1100];
	cin >> a[0];
	for (int i = 1; i < N; i++) {
		cout << a[i - 1] << " ";
		cin >> a[i];
	}
	cout << a[N - 1] << endl;
	insertionSort(a, N);
}

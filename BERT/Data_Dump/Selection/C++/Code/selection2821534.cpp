#include<iostream>
#include<algorithm>

using namespace std;

int selectionSort(int A[], int N) {
	int i, j, t, sw = 0, minj;
	for (i = 0;i < N - 1;i++) {
		minj = i;
		for (j = i;j < N;j++) {
			if (A[j] < A[minj])minj = j;
		}
		swap(A[i], A[minj]);
		if (i != minj)sw++;
	}
	return sw;
}

int main() {
	int N;
	cin >> N;
	int a[114514];
	int i, j;
	for (i = 0;i < N;i++) {
		cin >> a[i];
	}
	int sw = selectionSort(a, N);
	for (int i = 0;i < N;i++) {
		if (i)cout << " ";
		cout << a[i];
	}
	
	cout << endl;
	cout << sw << endl;
	return 0;
}

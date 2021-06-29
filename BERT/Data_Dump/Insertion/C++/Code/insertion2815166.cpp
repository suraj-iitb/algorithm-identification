#include<iostream>
#include<algorithm>

using namespace std;

void trace(int a[], int N) {
	int i;
	for (i = 0;i < N;i++) {
		if (i != 0)cout << " ";
		cout << a[i];
	}
	cout << endl;
}

void insertionSort(int a[], int N) {
	int i, j, v;
	for (i = 1;i < N;i++) {
		v = a[i];
		for (j = i - 1;j >= 0 && a[j] > v;j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = v;
		trace(a, N);
	}
}

int main() {
	int N;
	cin >> N;
	int a[114514];
	int i, j;
	for (i = 0;i < N;i++) {
		cin >> a[i];
	}
	trace(a, N);
	insertionSort(a, N);
	return 0;
}

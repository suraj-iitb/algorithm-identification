#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void selectionSort(int a[], int N) {
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (a[i] != a[minj]) {
			swap(a[i], a[minj]);
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N; cin >> N;
	int a[110];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	selectionSort(a, N);
	for (int i = 0; i < N - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[N - 1] << endl;
	cout << cnt << endl;
}

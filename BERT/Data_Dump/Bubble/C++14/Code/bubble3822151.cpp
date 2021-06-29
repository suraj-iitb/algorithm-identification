#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void bubbleSort(int A[], int N) {
	int flag = 1;
	while (flag){
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				cnt++;
			}
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
	bubbleSort(a, N);
	for (int i = 0; i < N - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[N - 1] << endl;
	cout << cnt << endl;
}

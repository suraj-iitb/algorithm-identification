#include <bits/stdc++.h>
using namespace std;

void printsort (int A[], int N) {
	for (int i = 0; i < N - 1; i++){
		cout << A[i] << " ";
		}
	cout<< A[N -1] << endl;
}

int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		A[i] = x;
	}
	
    printsort(A, N);
	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j+1] = v;
		printsort(A, N);
	}
// 	cout << endl;
	return 0;
}


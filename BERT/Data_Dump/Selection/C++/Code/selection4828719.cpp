#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int A[100];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int count = 0;
	for (int i = 0; i < N; i++) {

		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[minj] > A[j]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			count++;
		}

	}
	for (int i = 0; i < N; i++) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;
}

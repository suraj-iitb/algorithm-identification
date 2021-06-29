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

	int i = 0;
	int flag = 1;
	int count = 0;
	while (flag) {
		flag = 0;
		for (int j = (N - 1); j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				count++;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << count << endl;
}


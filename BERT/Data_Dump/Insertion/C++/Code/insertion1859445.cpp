#include <bits/stdc++.h>
using namespace std;

int main()
{

	int N;
	int A[100];
	int key;
	int j;
	cin >> N;
	if (N <= 0 || N > 100)return 0;
	for (int i = 0; i<N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int m = 0; m<N-1; m++) {
			cout << A[m] << " ";
		}
		cout<<A[N-1]<< endl;
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j]>key) {
			A[j + 1] = A[j];
			A[j] = key;
			j--;
		}
	}
	for (int m = 0; m<N - 1; m++) {
		cout << A[m] << " ";
	}
	cout << A[N - 1] << endl;
    return 0;
}

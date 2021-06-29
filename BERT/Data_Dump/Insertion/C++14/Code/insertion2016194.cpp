#include <bits/stdc++.h>
using namespace std;
int N, A[100];

void Out() {
	cout << A[0];
	for (int i = 1; i < N; i++)
		cout << ' ' << A[i];
	cout << endl;
}

void InsertionSort() {
	for (int i = 1; i < N; i++) {
		int v = A[i], j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		Out();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	Out();
	InsertionSort();
	return 0;
}

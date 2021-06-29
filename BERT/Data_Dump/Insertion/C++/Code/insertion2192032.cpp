#include<iostream>
using namespace std;
int main() {
	int A[101], N, i, j, temp;
	cin >> N;
	for (i = 0; i < N; i++)cin >> A[i];
	for (int i = 0; i < N; i++) {
		temp = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > temp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = temp;
		for (j = 0; j < N; j++) {
			cout << A[j];
			if (j != N - 1)cout << " ";
		}
		cout << endl;
	}
}

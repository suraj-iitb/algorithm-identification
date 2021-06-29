#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 100;

int main(){
	int n;
	cin >> n;
	int A[MAX];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n - 1; i++) {
		cout << A[i] << ' ';
	}
	cout << A[n - 1] << endl;

	for (int i = 1; i < n; i++) {
		int v = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (int k = 0; k < n - 1; k++) {
			cout << A[k] << ' ';
		}
		cout << A[n - 1] << endl;
	}

	return 0;
}

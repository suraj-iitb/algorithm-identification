#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, A[100];
	cin >> N;

	for (int k = 0; k < N; k++) cin >> A[k];
	cout << A[0];
	for (int m = 1; m < N; m++) cout << " " << A[m];
	cout << endl;

	for (int i = 1 ; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		while(j >=0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		cout << A[0];
		for (int l = 1; l < N; l++) {
			cout << " " << A[l];
		}
		cout << "\n";
	}

	return 0;

}

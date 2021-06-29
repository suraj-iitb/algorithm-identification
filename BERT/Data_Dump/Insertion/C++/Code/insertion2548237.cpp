#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A[100] = { 0 };
	int N;
	cin >> N;
	int v;
	for (int i = 0;i < N;i++) 	cin >> A[i];
	
	for (int i = 0;i < N;i++){
		v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
		for (int k = 0;k < N;k++) {
			cout << A[k];
			if (k != N - 1) cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}

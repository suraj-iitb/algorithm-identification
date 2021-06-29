#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//ローカル変数はstaticで初期化


int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N-1; i++)cout << A[i]<<' '; cout <<A[N-1]<< endl;

	for (int i = 1; i <= N - 1; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
	for (int i = 0; i < N-1; i++)cout << A[i]<<' '; cout <<A[N-1]<< endl;
	}
	




	return 0;
}

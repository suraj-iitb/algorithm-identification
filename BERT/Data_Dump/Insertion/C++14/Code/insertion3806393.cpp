#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>	

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < N; ++i) {
		int a;
		a = A[i];
		int j = i - 1;
		while (j >= 0 && a < A[j]) {
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = a;
		for (int k = 0; k < N - 1; ++k) {
			cout << A[k] << " ";
		}
		cout << A[N - 1] << endl;
	}
	


	return 0;
}

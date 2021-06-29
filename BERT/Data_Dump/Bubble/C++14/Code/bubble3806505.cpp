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

	bool flag = true;
	int count = 0;
	for(int j = 0; flag; ++j){
		flag = 0;
		for (int i = N - 1; i > j; --i) {
			if (A[i] < A[i - 1]) {
				swap(A[i], A[i - 1]);
				++count;
				flag = 1;
			}
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		cout << A[i] << " ";
	}
	cout << A[N - 1] << endl;
	cout << count << endl;
	return 0;
}

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
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	int count = 0;

	for (int i = 0; i < n; ++i) {
		int minValue_point = i;
		for (int j = i + 1; j < n; ++j) {
			if (A[j] < A[minValue_point]) {
				minValue_point = j;
			}
		}
		if (minValue_point != i)
		{
			swap(A[i], A[minValue_point]);
			++count;
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		cout << A[i] << " ";
	}
	cout << A[n - 1] << endl;
	cout << count << endl;
	return 0;
}

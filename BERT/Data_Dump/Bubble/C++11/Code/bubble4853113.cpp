#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>
#include<queue>
#include<bitset>

using namespace std;

int bubble(vector<int>& A, int N) {
	int sw = 0;
	bool flag = true;
	for (int i = 0; flag; ++i) {
		flag = 0;
		for (int j = N - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = true;
				sw++;
			}
		}
	}
	return sw;
}

int main() {
	vector<int>A(100);
	int N, sw;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> A.at(i);
	}

	sw = bubble(A, N);

	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << A.at(i);
	}

	cout << endl;
	cout << sw << endl;;

	return 0;
}

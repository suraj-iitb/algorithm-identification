#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>	
#include<list>

constexpr auto PI = 3.14159265359;

using namespace std;


int make_partition(vector<pair<int, char>>& A, int p, int r) {
	int x = A[r].first;
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (A[j].first <= x) {
			++i;
			swap(A[j], A[i]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quickSort(vector<pair<int, char>>& A, int p, int r) {
	if (p < r) {
		int q = make_partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<pair<int, char>> A(N);
	vector<tuple<int, int, char>> stable_A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
		stable_A[i] = make_tuple(A[i].first, i, A[i].second);
	}

	quickSort(A, 0, A.size() - 1);
	stable_sort(stable_A.begin(), stable_A.end());

	string stable = "Stable";
	for (int i = 0; i < A.size(); ++i) {
		if (A[i].second != get<2>(stable_A[i])) {
			stable = "Not stable";
		}
	}
	cout << stable << endl;

	for (int i = 0; i < N; ++i) {
		cout << A[i].second << " " << A[i].first << endl;
	}

	return 0;
}

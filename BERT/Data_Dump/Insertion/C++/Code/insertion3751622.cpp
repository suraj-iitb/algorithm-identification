#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main() {

	long N; cin >> N;
	vector<long> A; A.push_back(0);
	for (int i = 1; i <= N; i++) { long inp; cin >> inp; A.push_back(inp); } //入力。先頭は0。

	for (int i = 1; i <= N; i++) {
        int ind = i;
		while (A[ind] < A[ind - 1]) { swap(A[ind - 1], A[ind]); ind--; } 

		for (int j = 1; j <= N; j++) cout << (j==1?"":" ") << A[j]; //出力。
		cout << endl;
	}
}

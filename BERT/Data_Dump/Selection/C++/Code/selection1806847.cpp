#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

int selectionSort(int A[], int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		swap(A[i], A[minj]);
		if (i != minj)
			cnt++;
	}
	return cnt;
}

int main() {
	int N; cin >> N;
	int A[100];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int cnt = selectionSort(A, N);
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N - 1)cout << " ";
	}
	cout << endl;
	cout << cnt << endl;

	return 0;
}

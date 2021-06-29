#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <deque>
#define ll long long

using namespace std;

vector<int>S;
int cnt;

void merge(int left, int mid, int right) {
	vector<int>L(mid - left + 1), R(right - mid + 1);
	for (int i = 0; i < mid - left; i++) {
		L[i] = S[left + i];
	}
	for (int i = 0; i < right - mid; i++) {
		R[i] = S[mid + i];
	}
	L[mid - left] = 1010001000;
	R[right - mid] = 1010001000;
	int curL = 0;
	int curR = 0;
	for (int i = left; i < right; i++) {
		cnt++;
		if (L[curL] <= R[curR]) {
			S[i] = L[curL];
			curL++;
		}
		else {
			S[i] = R[curR];
			curR++;
		}
	}
}

void mergeSort(int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}

int main() {
	int n; cin >> n;
	S.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	mergeSort(0, n);

	for (int i = 0; i < S.size(); i++) {
		if (i != 0)cout << " ";
		cout << S[i];
	}
	cout << endl << cnt << endl;



	return 0;
}




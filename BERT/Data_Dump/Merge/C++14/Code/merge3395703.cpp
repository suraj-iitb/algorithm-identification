// ConsoleApplication.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#define _USE_MATH_DEFINES

#include "stdio.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <array>

using namespace std;

int INF = 1000000000;
int MAX = 5000001;

void merge(vector<int>& A, const int left, const int mid, const int right, int & cnt, vector<int>& L, vector<int>& R) {
	L.clear();  L.insert(L.end(), A.begin() + left, A.begin() + mid); L.push_back(INF);
	R.clear();  R.insert(R.end(), A.begin() + mid, A.begin() + right); R.push_back(INF);
	int i = 0, j = 0;
	cnt += right - left;
	for (int k = left; k != right; ++k) {
		A.at(k) = L.at(i) <= R.at(j) ? L.at(i++) : R.at(j++);
	}

}

void mergeSort(vector<int>& A, const int left, const int right, int& cnt, vector<int>& L, vector<int>& R) {
	if ( !(left + 1 < right) ) return;
	const int mid = (left + right) / 2;
	mergeSort(A, left, mid, cnt, L, R);
	mergeSort(A, mid, right, cnt, L, R);
	merge(A, left, mid, right, cnt, L, R);
}

int mergeSort(vector<int>& A) {
	int cnt = 0;
	vector<int> L, R;
	L.reserve(MAX);
	R.reserve(MAX);
	mergeSort(A, 0, A.size(), cnt, L,R);
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& i : A)cin >> i;
	const int swapCount = mergeSort(A);
	/*const string out = accumulate(A.begin() + 1, A.end(), to_string(A.front()), [&](const string& init, const int val) {
		return init + " " + to_string(val);
	});
	cout << out << endl;
	*/
	cout << A.front();
	for_each(A.begin() + 1, A.end(), [](const int i) {cout << " " << i; });
	cout << endl;
	cout << swapCount << endl;


	return 0;
}

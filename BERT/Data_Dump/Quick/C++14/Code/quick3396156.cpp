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


struct Card {
	string name;
	int num;
	Card() {}
	Card(const string& name, const int num):name(name),num(num){}
	bool operator==(const Card& rhs)const { return name == rhs.name && num == rhs.num; }
	bool operator<(const Card& rhs)const { return num < rhs.num; }
	bool operator<=(const Card& rhs)const { return num <= rhs.num; }
};

istream& operator>>(istream& is, Card& c) {
	is >> c.name;
	is >> c.num;
	return is;
}

ostream& operator<<(ostream& os, const Card& c) {
	os << c.name << " " << c.num;
	return os;
}

template<typename T>
int partition(vector<T>& A, int p, int r)
{
	T& x = A.at(r);
	for (int j = p; j != r; ++j) if (A.at(j) <= x) swap(A.at(p++), A.at(j));
	swap(A.at(p), x);
	return p;
}

template<typename T>
void quickSort(vector<T>& A, int p, int r) {
	if (p < r) {
		const int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

template<typename T>
void quickSort(vector<T>& A) {
	quickSort(A, 0, A.size() - 1);
}
//
//
//void merge(vector<int>& A, const int left, const int mid, const int right, int & cnt, vector<int>& L, vector<int>& R) {
//	L.clear();  L.insert(L.end(), A.begin() + left, A.begin() + mid); L.push_back(INF);
//	R.clear();  R.insert(R.end(), A.begin() + mid, A.begin() + right); R.push_back(INF);
//	int i = 0, j = 0;
//	cnt += right - left;
//	for (int k = left; k != right; ++k) {
//		A.at(k) = L.at(i) <= R.at(j) ? L.at(i++) : R.at(j++);
//	}
//
//}
//
//void mergeSort(vector<int>& A, const int left, const int right, int& cnt, vector<int>& L, vector<int>& R) {
//	if (!(left + 1 < right)) return;
//	const int mid = (left + right) / 2;
//	mergeSort(A, left, mid, cnt, L, R);
//	mergeSort(A, mid, right, cnt, L, R);
//	merge(A, left, mid, right, cnt, L, R);
//}
//
//int mergeSort(vector<int>& A) {
//	int cnt = 0;
//	vector<int> L, R;
//	L.reserve(MAX);
//	R.reserve(MAX);
//	mergeSort(A, 0, A.size(), cnt, L, R);
//	return cnt;
//}

int main()
{
	int n;
	cin >> n;
	vector<Card> A(n);
	for (auto& c : A) cin >> c;
	vector<Card> B(A);
	quickSort(A);
	stable_sort(B.begin(), B.end());
	cout << (A == B ? "Stable" : "Not stable") << endl;
	for (const auto& c : A)cout << c << endl;

	return 0;
}

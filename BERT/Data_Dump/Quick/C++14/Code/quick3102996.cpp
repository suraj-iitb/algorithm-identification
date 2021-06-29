#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
//#include "libs.h"
#include <random>
#include <unordered_map>
#include <unordered_set>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>

using namespace std;

//呪文
#define DUMPOUT cerr
#define dump(...) DUMPOUT<<"  ";DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;DUMPOUT<<"    ";dump_func(__VA_ARGS__)

typedef unsigned uint; typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd; typedef pair<string, string> pss;
template <typename _KTy, typename _Ty> ostream& operator << (ostream& o, const pair<_KTy, _Ty>& m) { o << "{" << m.first << ", " << m.second << "}"; return o; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& o, const map<_KTy, _Ty>& m) { if (m.empty()) { o << "{ }"; return o; } o << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& o, const unordered_map<_KTy, _Ty>& m) { if (m.empty()) { o << "{ }"; return o; } o << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const vector<_Ty>& v) { if (v.empty()) { o << "{ }"; return o; } o << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const set<_Ty>& s) { if (s.empty()) { o << "{ }"; return o; } o << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { o << ", " << *itr; } o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const unordered_set<_Ty>& s) { if (s.empty()) { o << "{ }"; return o; } o << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { o << ", " << *itr; }	o << "}"; return o; }
template <typename _Ty> ostream& operator << (ostream& o, const stack<_Ty>& s) { if (s.empty()) { o << "{ }"; return o; } stack<_Ty> t(s); o << "{" << t.top(); t.pop(); while (!t.empty()) { o << ", " << t.top(); t.pop(); } o << "}";	return o; }
template <typename _Ty> ostream& operator << (ostream& o, const list<_Ty>& l) { if (l.empty()) { o << "{ }"; return o; } o << "{" << l.front(); for (auto itr = ++l.begin(); itr != l.end(); ++itr) { o << ", " << *itr; } o << "}"; return o; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& is, pair<_KTy, _Ty>& m) { is >> m.first >> m.second; return is; }
template <typename _Ty> istream& operator >> (istream& is, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) is >> v[i]; return is; }
namespace aux { // print tuple
	template<typename Ty, unsigned N, unsigned L> struct tp { static void print(ostream& os, const Ty& v) { os << get<N>(v) << ", "; tp<Ty, N + 1, L>::print(os, v); } };
	template<typename Ty, unsigned N> struct tp<Ty, N, N> { static void print(ostream& os, const Ty& v) { os << get<N>(v); } };
}
template<typename... Tys> ostream& operator<<(ostream& os, const tuple<Tys...>& t) { os << "{"; aux::tp<tuple<Tys...>, 0, sizeof...(Tys)-1>::print(os, t); os << "}"; return os; }

template<typename A, size_t N, typename T> inline void Fill(A(&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head&& head, Tail&&... tail) { DUMPOUT << head; if (sizeof...(Tail) == 0) { DUMPOUT << " "; } else { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#define PI 3.14159265358979323846
#define EPS 1e-10
#define FOR(is,a,n) for(int is=(a);is<(n);++is)
#define REP(is,n)  FOR(is,0,n)
#define all(j) (j).begin(), (j).end()
#define SZ(j) ((int)(j).size())
#define fake false



template<typename T> void printVec(const vector<T>& v, char delim = ' ', ostream& os = cout) {
	os << v[0];
	for (int i = 1; i < v.size(); i++)
		os << delim << v[i];
	os << endl;
}

struct SCard {
	char suit;
	int val;
	SCard() {}
	SCard(char suit, int val) : suit(suit), val(val) {}
};
ostream& operator<<(ostream& os, const SCard& card) {
	os << card.suit << " " << card.val;
	return os;
}

size_t merge(vector<SCard>& A, int left, int mid, int right) {
	size_t numCmp = 0;
	int n1 = mid - left;
	int n2 = right - mid;
	vector<SCard> L(n1 + 1), R(n2 + 1);
	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	L[n1].val = R[n2].val = INT_MAX;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		numCmp++;
		if (L[i].val <= R[j].val)
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
	return numCmp;
}

size_t mergeSort(vector<SCard>& A, int left, int right) {
	size_t numCmp = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		numCmp += mergeSort(A, left, mid);
		numCmp += mergeSort(A, mid, right);
		numCmp += merge(A, left, mid, right);
	}
	return numCmp;
}

int partition(vector<SCard>& A, int p, int r) {
	SCard x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (A[j].val <= x.val) {
			i = i + 1;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quickSort(vector<SCard>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}



int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<SCard> cards;
	REP(i, n) {
		char suit;
		int val;
		cin >> suit >> val;
		cards.emplace_back(suit, val);
	}

	vector<SCard> cards_merge(cards);
	mergeSort(cards_merge, 0, n);

	vector<SCard> cards_qsort(cards);
	quickSort(cards_qsort, 0, n - 1);

	bool flag = true;
	for (int i = 0; i < n; i++)
		if (cards_merge[i].suit != cards_qsort[i].suit)
			flag = false;
	cout << (flag ? "Stable" : "Not stable") << endl;
	printVec(cards_qsort, '\n');	

	return 0;
}


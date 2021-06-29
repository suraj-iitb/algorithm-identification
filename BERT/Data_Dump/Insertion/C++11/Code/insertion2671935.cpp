#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <functional>
#include <set>
#include <numeric>
#include <stack>
#include <utility>
#include <time.h>
#include <iterator>
#include <random>
//#include "util.h"

using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<bool> vbool;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//呪文
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { cout << "{" << m.first << ", " << m.second << "}"; return ostr; }
template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { cout << "{ }"; return ostr; } cout << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { cout << ", " << *itr; } cout << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { cout << "{ }"; return ostr; }	cout << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { cout << ", " << *itr; }	cout << "}"; return ostr; }
template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { cout << "{ }"; return ostr; } cout << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) { cout << ", " << *itr; }	cout << "}"; return ostr; }
template <typename _KTy, typename _Ty> istream& operator >> (istream& istr, pair<_KTy, _Ty>& m) { cin >> m.first >> m.second; return istr; }
template <typename _Ty> istream& operator >> (istream& istr, vector<_Ty>& v) { for (size_t i = 0; i < v.size(); i++) cin >> v[i]; return istr; }
ll modpow(ll n, ll p, ll m) { ll result = 1; while (p > 0) { if (p & 1) result = (result * n) % m; p >>= 1; n = (n * n) % m; } return result; }
template <typename _Ty> _Ty ipow(_Ty x, _Ty n) { _Ty ret = _Ty(1); for (_Ty i = _Ty(0); i < n; i++) ret *= x; return ret; }
#define PI 3.14159265358979323846
#define EPS 1e-8
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define all(x) (x).begin(), (x).end()
#define fake false


void insertionSort(vector<int>& A) {
	int N = A.size();
	for (int i = 1; i <= N - 1; i++) {
		//print
		cout << A[0];
		for (int i = 1; i < A.size(); i++)
			cout << " " << A[i];
		cout << endl;

		int v = A[i];
		int j;
		for (j = i - 1; j >= 0 && A[j] > v; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = v;
	}
	//print
	cout << A[0];
	for (int i = 1; i < A.size(); i++)
		cout << " " << A[i];
	cout << endl;
}

int main()
{
	//clock_t start, end;
	//start = clock();

	int n; cin >> n;
	vector<int> A(n);
	cin >> A;

	insertionSort(A);
	
	//end = clock();
	//printf("%d msec.\n", end - start);

	return 0;
}


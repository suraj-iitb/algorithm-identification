#pragma GCC optimize("Ofast")
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <stack>
#include <queue>
#include <list>
#include <map>
//#include <unordered_map>  

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=ll(a);i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define PB push_back
#define SIZE(x) ll(x.size())
#define ALL(x) x.begin(),x.end()
#define INF 1000000000000
#define MOD 1000000007
#define PI 3.14159265358979323846
#define endl "\n"

//vector<vector<ll> > data(3, vector<ll>(4));
//vector<ll> data(N);
//v.erase(remove(v.begin(), v.end(), value_to_remove), v.end());
//int num = atoi(numStr.c_str());
//str s = to_string(i);
//int i = c - '0'
//sort(data.begin(), data.end());
//reverse(data.begin(), data.end());
//data.erase(unique(data.begin(), data.end()), data.end()); //重複なし
//str.substr(n)//n番以降スライス
//str.substr(n,m)//n番以降m文字スライス
//str.erase(n)//n番以降削除
//str.erase(n,m)//n番以降m文字削除
//str.find(str_to_find)//位置 or string::npos
//cout << fixed << setprecision(15) << n;
//while (cin >> c){if (c == EOF) break;

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
/*
bool isOK(ll index) {
	ll k = 0;
	REP(i, m) {
		ll q = p[index];
		while (q >= w[k] && w[k]>0) {
			q -= w[k];
			k++;
		}
	}
	if (k >= n)return true;
	else return false;
}

ll binary() {
	ll ng = -1;
	ll ok = (ll)p.size();
	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		if (isOK(mid)) ok = mid;
		else ng = mid;
	}
	return ok;
}
*/

ll powmod(ll x, ll n) {
	ll s=1;
	REP(i, n) {
		s = s*x%MOD;
	}
	if (s < 0)s += MOD;
	return s;
}

ll n,c = 0;
vector<pair<char, ll> > A(100000, { 'A',-1 });

ll partition(vector<pair<char, ll> > &A,ll p ,ll r) {
	ll x = A[r].second;
	ll i = p - 1;
	FOR(j, p, r - 1) {
		if (A[j].second <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quickSort(vector< pair<char, ll> >& A, ll p, ll r) {
	if (p < r) {
		ll q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

signed main() {
	cin >> n;
	REP(i, n) {
		cin >> A[i].first >> A[i].second;
	}
	map<int, string> m1, m2;
	for (int i = 0; i < n; i++) m1[A[i].second] += A[i].first;
	quickSort(A, 0, n - 1);
	for (int i = 0; i < n; i++) m2[A[i].second] += A[i].first;
	bool flag = 1;
	
	REP(i, n) flag &= m1[A[i].second] == m2[A[i].second];
	
	if (flag)cout << "Stable" << endl;
	else cout << "Not stable" << endl;

	REP(i, n) {
		cout << A[i].first << " " << A[i].second << endl;
	}
}




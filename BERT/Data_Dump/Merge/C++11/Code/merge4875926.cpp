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
#include <unordered_map>  

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
vector<ll> A(500000,-1);

void merge(vector<ll> &A,ll left,ll mid,ll right){
	ll n1 = mid - left, n2 = right - mid;
	vector<ll> L(n1 + 1), R(n2+1);
	REP(i, n1)L[i] = A[left + i];
	REP(i, n2)R[i] = A[mid + i];
	L[n1] = INF;
	R[n2] = INF;
	ll i = 0,j = 0;
	FOR(k, left, right - 1) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		c++;
	}
}

void mergeSort(vector<ll>& A, ll left, ll right) {
	if (left + 1 < right) {
		ll mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

signed main() {
	cin >> n;
	REP(i, n)cin >> A[i];
	mergeSort(A, 0, n);
	REP(i, n) {
		cout << A[i];
		i == n - 1 ? cout << endl : cout << " ";
	}
	cout << c << endl;
}




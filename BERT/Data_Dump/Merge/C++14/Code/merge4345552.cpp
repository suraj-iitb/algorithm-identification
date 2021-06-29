#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const int INF = 1e9 + 7;
ll gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	if (y == 0)return abs(x - y);
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
using Graph = vector<vector<int>>;
ll mypow(ll x, ll n, ll m) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return mypow(x*x%m, n / 2, m);
	}
	else {
		return x * mypow(x, n - 1, m) % m;
	}
}
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
//テーブルをつくる前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;//mod pにおける1,2,,,nの逆元
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i%INF;
		inv[i] = INF - inv[INF%i] * (INF / i) % INF;
		finv[i] = finv[i - 1] * inv[i] % INF;
	}
}

ll COM(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (finv[k] * finv[n - k] % INF) % INF;
}
///////////////////////////////////////

int L[500010];
int R[500010];
int a[500010];
int n;
int cnt = 0;
void merge(int A[], int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; ++i) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		R[i] = A[mid + i];
	}
	L[n1] = INF;
	R[n2] = INF;
	int i = 0, j = 0;
	for (int k = left; k < right; ++k) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}
void mergesort(int A[], int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergesort(A, n, left, mid);
		mergesort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mergesort(a, n, 0,n);
	for (int i = 0; i < n; ++i) {
		if (i)cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}


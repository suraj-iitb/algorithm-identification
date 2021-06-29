#include <stdio.h>
#include <sstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <limits>
#include <iomanip>
#include <ctype.h>
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
#define bit(x,v) ((ll)x << v)

const ll INF = 1000000007;
const int MAX = 210000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}

ll bit[200010];
int max_n = 200000;
int pm = 0;
void add(int x) {

	while (max_n >= x)
	{
		bit[x]++;
		x += x & -x;
	}
}
void sub(int x) {
	while (max_n >= x)
	{
		bit[x]--;
		x += x & -x;
	}
}
int merge(int *a, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	for (size_t i = 0; i < n1; i++)
	{
		L[i] = a[left + i];
	}
	for (size_t i = 0; i < n2; i++)
	{
		R[i] = a[mid + i];
	}

	L[n1] = INF;
	R[n2] = INF;
	int i = 0;
	int j = 0;
	for (size_t k = left; k < right; k++)
	{
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;

		}
		else {
			a[k] = R[j];
			j++;
		}
	}
	return i + j;
}
ll mergeSort(int *a, int left, int right) {
	int res = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		res = mergeSort(a, left, mid);
		res += mergeSort(a, mid, right);
		res += merge(a, left, mid, right);
	}
	return res;
}

void solv() {
	
	int n;
	cin >> n;

	int a[500050];
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int res = mergeSort(a, 0, n);
	for (size_t i = 0; i < n; i++)
	{
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl  << res << endl;
}
int main() {
	//	COMinit();
	solv();
	return 0;
}


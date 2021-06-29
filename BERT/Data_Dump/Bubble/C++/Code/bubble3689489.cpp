#pragma once
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
int search(int x) {

	int k = 0;
	int p = 1;
	while (p * 2 <= max_n)
	{
		p *= 2;
	}
	for (int i = p; i > 0; i /= 2)
	{
		if (i + k < max_n && bit[i + k] < x) {
			x -= bit[i + k];
			k += i;
		}
	}
	return k + 1;
}
void solv() {
	int n;
	cin >> n;
	int a[110];
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int p = 0;
	while (true)
	{
		bool ok = true;
		for (size_t i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				ok = false;
				p++;
			}
		}
		if (ok) break;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << p << endl;
}
int main() {
	//	COMinit();
	solv();
	return 0;
}


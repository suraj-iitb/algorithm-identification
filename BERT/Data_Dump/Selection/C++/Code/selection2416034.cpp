#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
typedef long long ll;
using namespace std;

int main() {
	//freopen("run.in", "r", stdin);
	//freopen("run.out", "w", stdout);

	int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 0; i <= n - 2; i++) {
		int min, idx;

		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (i != min) {
			swap(a[i], a[min]);
			cnt++;
		}
	}
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << ' ' << a[i];
	}
	cout << endl << cnt << endl;
}

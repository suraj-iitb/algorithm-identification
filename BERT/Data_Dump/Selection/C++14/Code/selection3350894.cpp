#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <bitset>
#include <random>
#include <functional>
#include <sstream>
#include <iomanip>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define REVE(x) reverse((x).begin(),(x).end())
#define MP make_pair
#define PB push_back

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef long long LL;

int main() {
	int n, cnt = 0;
	cin >> n;
	VI a(n);
	rep(i, n)cin >> a[i];

	//sort
	rep(i, n) {
		int mini = i;
		FOR(j, i, n) {
			if (a[j] < a[mini])mini = j;
		}
		swap(a[i], a[mini]);
		if (i != mini)cnt++;
	}

	rep(i, n) {
		cout << a[i];
		printf(i == n - 1 ? "\n" : " ");
	}
	cout << cnt << endl;
}

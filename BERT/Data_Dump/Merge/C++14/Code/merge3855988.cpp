#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, s[500010], cnt;
void merge(int left, int mid, int right) {
	cnt += right - left;
	int n1 = mid - left, n2 = right - mid;
	int* l = new int[n1 + 1], * r = new int[n2 + 1];
	rep(i, n1)l[i] = s[left + i];
	rep(i, n2)r[i] = s[mid + i];
	l[n1] = r[n2] = INF;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (l[i] < r[j]) {
			s[k] = l[i];
			i++;
		}
		else {
			s[k] = r[j];
			j++;
		}
	}
}

void mergesort(int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergesort(left, mid);
		mergesort(mid, right);
		merge(left, mid, right);
	}
}
signed main() {
	cin >> n;
	rep(i, n)cin >> s[i];
	mergesort(0, n);
	rep(i, n - 1)cout << s[i] << " ";
	cout << s[n - 1] << endl << cnt << endl;
}

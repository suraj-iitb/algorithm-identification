#define _USE_MATH_DEFINES
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <iomanip>
#include <numeric>
#include <list>
#include <utility>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repa(i,a,b) for(int i=(int)a;i<=(int)b;i++);
#define irep(i,n) for(int i=(int)n-1;i>=0;i--);

void trace(int a[], int n) {
	rep(i, n - 1)cout << a[i] << " ";
	cout << a[n - 1] << endl;
}

int bubblesort(int a[], int n) {
	int ans = 0;
	int flag = 1; int j;
	while (flag) {
		flag = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				flag = 1;
				ans++;
			}
		}
	}
	return ans;
}

int n; int table[101];
int main() {
	cin >> n; rep(i, n)cin >> table[i];
	int ans = bubblesort(table, n);
	trace(table, n);
	cout << ans << endl;
	return 0;
}

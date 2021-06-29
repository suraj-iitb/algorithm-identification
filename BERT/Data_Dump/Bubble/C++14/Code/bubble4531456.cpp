#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>

typedef  long long ll;
#define mop 1000000007
#define mop2 998244353

using namespace std;

void print(vector <ll> v) {
	for (auto itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr;
		if (itr + 1 != v.end()) {
			cout << " ";
		}
	}
	cout << endl;
}

ll bubbleSort(vector <ll> v) {
	ll ans = 0;
	ll n = v.size();
	bool flag = true;
	while (flag) {
		flag = false;
		ll i = 1;
		for (ll j = n - 1; j >= i; j--) {
			if (v[j] < v[j - 1]) {
				swap(v[j], v[j - 1]);
				ans++;
				flag = true;
			}
		}
		i++;
	}
	print(v);
	return ans;
}

int main() {
	ll n;
	cin >> n;
	vector <ll> v;
	v.resize(n);
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;
		v[i] = tmp;
	}
	
	cout << bubbleSort(v) << endl;
}

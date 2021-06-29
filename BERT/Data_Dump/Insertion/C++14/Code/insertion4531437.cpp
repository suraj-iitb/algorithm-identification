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
		if (itr+1 != v.end()) {
			cout << " ";
		}
	}
	cout << endl;
}

void insertionSort(vector <ll> v) {
	ll n = v.size();
	for (ll i = 0; i < n; i++) {
		ll vt = v[i];
		ll j = i - 1;
		while (j >= 0 && vt < v[j]) {
			v[j + 1] = v[j];
			j--;
		}
		v[j+1] = vt;
		print(v);
	}
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
	insertionSort(v);
	
}

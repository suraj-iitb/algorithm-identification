#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for(int k = 0; k < n; ++k) {
		if( k > 0 ) cout << " ";
		cout << a[k];
	}
	
	cout << endl;
	
	for(int i = 1; i < n; ++i) {
		int v = a[i];
		int j = i - 1;
		
		while( j >= 0 && a[j] > v ) {
			a[j + 1] = a[j];
			j--;
		}
		
		a[j + 1] = v;
		
		for(int k = 0; k < n; ++k) {
			if( k > 0 ) cout << " ";
			cout << a[k];
		}
		
		cout << endl;
	}
	
	return 0;
}


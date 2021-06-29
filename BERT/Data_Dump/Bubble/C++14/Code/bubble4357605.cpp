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
	
	bool flag = true;
	int cnt = 0;
	while( flag ) {
		flag = false;
		
		for(int i = n - 1; i >= 1; i--) {
			if( a[i] < a[i - 1] ) {
				swap(a[i], a[i - 1]);
				flag = true;
				cnt++;
			}
		}
	}
	
	for(int i = 0; i < n; ++i) {
		if( i != 0 ) cout << " ";
		cout << a[i];
	}
	
	cout << endl;
	cout << cnt << endl;
	
	return 0;
}


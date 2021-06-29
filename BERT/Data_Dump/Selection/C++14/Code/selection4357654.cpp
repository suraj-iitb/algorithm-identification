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
	
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		int minj = i;
		
		for(int j = i; j < n; ++j) {
			if( a[j] < a[minj] ) {
				minj = j;
			}
		}
		
		swap(a[i], a[minj]);
		if( i != minj ) cnt++;
	}
	
	for(int i = 0; i < n; ++i) {
		if( i ) cout << " ";
		
		cout << a[i];
	}
	
	cout << endl;
	cout << cnt << endl;
	
	return 0;
}


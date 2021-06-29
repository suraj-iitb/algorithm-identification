#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n){
		cin >> a[i];
		printf("%d%c", a[i], (i == n - 1) ? '\n': ' ');
	}
	for(int i = 1; i < n; i++){
		int v = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		rep(k, n) printf("%d%c", a[k], (k == n - 1) ? '\n': ' ');
	}
	
	return 0;
}

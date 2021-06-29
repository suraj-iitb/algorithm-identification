#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		if (i != n-1)
			cout << a[i]<<" ";
		else
			cout << a[n-1] << endl;
	}
	int v(n);
	for(int i=1;i<=n-1;i++){
		v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		rep(i, n) {
			if(i!=n-1)
			cout << a[i]<<" ";
			else
			cout << a[n-1] << endl;
		}
	}
}

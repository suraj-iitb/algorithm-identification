#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
int main() {
	int n, count = 0;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
		cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
					int	x = a[i];
					a[i] = a[minj];
					a[minj] = x;
					if(i!=minj)
					count++;
	}
		rep(i, n) {
			if (i != n - 1)
				cout << a[i] << " ";
			else
				cout << a[n - 1] << endl;
		}
		cout << count << endl;
	
}



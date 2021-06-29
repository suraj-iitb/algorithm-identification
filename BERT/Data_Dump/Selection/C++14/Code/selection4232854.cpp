#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long LL;
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a)cin >> x;
	int cnt = 0;

	for (int i = 0; i < n ; i++) {
		int mipos = i;
		for (int j = i; j < n ; j++) {
			if (a[j] < a[mipos]) {
				mipos = j;
			}
		}
		if (i != mipos) {
			swap(a[i], a[mipos]);
			cnt++;
		}
	}
	rep(i, n) printf(i != n - 1 ? "%d " : "%d\n", a[i], a[i]);
	cout << cnt << endl;

	return 0;
}

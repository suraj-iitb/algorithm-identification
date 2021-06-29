#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> P;
#define int long long
#define ll long long
#define mod 1000000007
#define INF (1LL<<60)


signed main(){

	int n, a[100];
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int flag = true;
	while (flag){
		flag = false;
		for (int j = n - 1; j >= 1; j--){
			if (a[j] < a[j - 1]){
				swap(a[j], a[j - 1]);
				flag = true;
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout << a[i];
		if (i < n - 1) cout << " ";
		else cout << endl;
	}
	cout << ans << endl;

	return 0;
}


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

	for (int i = 0; i < n; i++){
		int minj = i;
		for (int j = i; j < n; j++){
			if (a[j] < a[minj])
				minj = j;
		}
		swap(a[i], a[minj]);
		if(i!=minj) ans++;
	}

	for (int i = 0; i < n; i++){
		cout << a[i];
		if (i < n - 1) cout << " ";
		else cout << endl;
	}
	cout << ans << endl;

	return 0;
}


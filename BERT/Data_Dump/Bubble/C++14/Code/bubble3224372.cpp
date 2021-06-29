#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int main()
{
	int n;
	cin >> n;
	int a[n];
	REP(i, n) cin >> a[i];
	
	int count = 0;
	bool flag = 0;
	do {
		flag = 0;
		REP(i, n-1){
			int tmp;
			if (a[i] > a[i+1]){
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				count++;
				flag = 1;
			}
		}
	} while (flag);

	REP(i, n){
		if (i < n-1) cout << a[i] << " ";
		else cout << a[i] << endl;
	}

	cout << count << endl;
}

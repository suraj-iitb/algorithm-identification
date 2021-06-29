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

	bool flag = 1;
	int fin = 0;
	int count = 0;

	do {
		int min = INF;
		int index;
		FOR(i, fin, n){
			if (min > a[i]){
				min = a[i];
				index = i;
			}
		}
		int tmp;
		if (min < a[fin]){
			tmp = a[fin];
			a[fin] = min;
			a[index] = tmp;
			count++;
		}

		fin++;

		if (fin == n) flag = 0;

	} while (flag);

	REP(i, n){
		if (i < n-1) cout << a[i] << " ";
		else cout << a[i] << endl;
	}

	cout << count << endl;


}

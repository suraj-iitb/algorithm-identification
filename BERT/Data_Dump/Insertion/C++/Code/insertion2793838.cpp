#include <bits/stdc++.h>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LLINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;



int main(void) {
	int n;
	int v;
	int j;

	cin >> n;
	vector<int>a(n);
	FOR(i, 0, n-1) {
		cin >> a[i];
	}
	FOR(i, 0, n - 2) {
		cout << a[i] << " ";
	}
	cout << a[n - 1] << endl;
	FOR(i, 1, n - 1) {
		v = a[i];
		j = i - 1;
		
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		FOR(i, 0, n - 2) {
			cout << a[i] << " ";
		}
		cout << a[n - 1] << endl;
	}


	return 0;
}


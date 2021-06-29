#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAX_A = 10000;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int a[n+1];
	rep(i,n) cin >> a[i+1];

	int b[n+1];
	int c[MAX_A+1] = {};

	FOR(i,1,n+1) c[a[i]]++;
	rep(i,MAX_A) c[i+1] = c[i] + c[i+1];
	RFOR(i,n+1,1){
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}

	FOR(i,1,n+1) cout << b[i] << (i == n ? "\n" : " ");
	
}

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<vector<pair<int, int> > > vvp;
typedef vector<pair<int, int> > vp;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<vector<ll> > vvl;
typedef vector<ll> vl;
typedef vector<vector<bool> > vvb;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef pair<int, int> pii;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define yn(f) (f?"yes":"no")
#define YN(f) (f?"YES":"NO")
#define Yn(f) (f?"Yes":"No")
#define mod 1000000007
#define nil -1
int main() {
	int v, e;
	cin >> v >> e;
	vvl A(v, vl(v, 1e18));
	for (int i = 0; i < v; i++)A[i][i] = 0;
	for (int i = 0; i < e; i++)
	{
		int s, t, d;
		cin >> s >> t >> d;
		A[s][t] = d;
	}
	bool f = false;
	for (int k = 0; k < v; k++)
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (A[i][k]==1e18||A[k][j]==1e18)continue;
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				if (i == j && A[i][j] < 0)f = true;
			}
		}
	}
	if (f) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (A[i][j] == 1e18)cout<<"INF";
				else cout << A[i][j];
				if (j != v - 1)cout << " ";
			}
			cout << endl;
		}
	}

}

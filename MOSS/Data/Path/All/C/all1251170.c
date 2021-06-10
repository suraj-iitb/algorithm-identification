#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) begin(a),end(a)
#define MS(m,v) memset(m,v,sizeof(m))
#define D10  fixed<<setprecision(10)
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> P;
typedef complex<double> Point;
typedef long long ll;
const ll INF = 114514810000;
const int MOD = 1000000007;
const double EPS = 1e-10;
const double PI = acos(-1.0);
struct edge
{
	int from, to, cost;
	bool operator < (const edge& e) const { return cost < e.cost; }
	bool operator >(const edge& e) const { return cost > e.cost; }
};
///*************************************************************************************///
///*************************************************************************************///
///*************************************************************************************///

int v, e;
ll d[105][105];

int main()
{
	cin >> v >> e;
	REP(i, v)REP(j, v) d[i][j] = (i == j ? 0 : INF);
	REP(i, e)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	REP(k, v)REP(i, v)REP(j, v) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	bool f = true;
	REP(i, v) if (d[i][i] < 0) f = false;
	if (f)
	{
		REP(i, v)
		{
			REP(j, v)
			{
				cout << (d[i][j] > INF/2 ? "INF" : to_string(d[i][j])) << (j==v-1?"\n":" ");
			}
		}
	}
	else puts("NEGATIVE CYCLE");
	return 0;
}

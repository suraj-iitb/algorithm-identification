#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<utility>//pair
#include<list>
#include<vector>//可変長配列
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define ll __int64
#define __int64 long long
#define P pair<int,int>
#define PP pair<ll,ll>
#define F first
#define S second
int dx[8] = { 1,0,-1,0,1,-1,-1,1 };
int dy[8] = { 0,1,0,-1,1,1,-1,-1 };

int n, m, r;
ll dist[111111];
const ll INF = 1e13;
vector<P>G[111111];

int main() {
	cin >> n >> m >> r;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].pb(mp(b, c));
	}

	priority_queue<PP, vector<PP>, greater<PP> >bfs;

	rep(i, n)dist[i] = INF;
	bfs.push(mp(0, r));

	while (!bfs.empty()) {
		ll d = bfs.top().first, from = bfs.top().second;
		bfs.pop();
		if (dist[from] != INF)
			continue;

		dist[from] = d;
		for (int i = 0; i < G[from].size(); i++) {
			ll to = G[from][i].first, next_cost = d+G[from][i].second;
			bfs.push(mp(next_cost, to));
		}
	}
	rep(i, n) {
		if (dist[i] == INF)cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}


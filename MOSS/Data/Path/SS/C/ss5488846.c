#include "bits/stdc++.h"
using namespace std;
using ll = long long; // デカい整数
using P = pair<ll, int>; // (長さ, 頂点番号)
const ll inf = 1ll<<60;

int main(){
	// input
	int v, e, r;
	cin >> v >> e >> r;
	vector<vector<P>> g(v);
	for(int i = 0; i < e; ++i){
		int s, t;
		ll d;
		cin >> s >> t >> d;
		g[s].push_back(P(d, t)); // 長さ、行先の頂点番号
	}
	//

	vector<ll> d(v, inf); // d[i] := 始点から頂点 i までの暫定最短距離
	vector<bool> f(v, false); // f[i] := 頂点 i が確定済みか
	priority_queue<P, vector<P>, greater<P> > q; // 確定済み頂点から行ける未確定頂点の(距離、番号)たち
	d[r] = 0;
	q.push(P(0, r));

	while(q.size()){
		// 確定済み頂点から行ける最も近い未確定頂点の
		ll cd = q.top().first; // 始点からの距離
		int cv = q.top().second; // 頂点番号
		q.pop();

		if(f[cv]) continue; // 確定済みなら捨てる
		f[cv] = true;
		for(P& e: g[cv]){
			// 今確定した頂点から出る辺それぞれの
			ll cost = e.first; // 長さ
			int to = e.second; // 行先の頂点番号
			if(cd + cost < d[to]){ // 枝刈り
				d[to] = cd + cost; // 候補追加
				q.push(P(d[to], to)); // 候補追加
			}
		}
	}

	for(ll& ans: d){
		if(ans == inf)cout << "INF\n";
		else cout << ans << endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

struct edge { ll to, cost; };//行き先,距離
// firstは最短距離、secondは頂点の番号
ll V;//頂点数
vector<edge> G[1000000LL]; ll d[1000000LL];//G=隣接リスト(vectorの配列),d=sからの距離
void dijkstra(ll s) {
	// greater<P>を指定することでfirstが小さい順に取り出せるようにする 
	priority_queue<P, vector<P>, greater<P>> que; 
	fill(d, d + V + 1, LINF);
	d[s] = 0LL;
	que.push(P(0LL, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		ll v = p.second;
		if (d[v] < p.first) continue;
		for (ll i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to)); 
			}
		}	 	
	}
}

int main(){
	ll e,r;cin>>V>>e>>r;
	for(int i = 0; i < e; i++) {
		ll s,t,d;cin>>s>>t>>d;
		edge e = {t,d};
		G[s].pb(e);
	}
	dijkstra(r);
	for(int i = 0; i < V; i++) {
		if (d[i] != LINF){
			cout << d[i] << endl;	
		}
		else{
			cout << "INF" << endl;
		}
	}
	return 0;
}

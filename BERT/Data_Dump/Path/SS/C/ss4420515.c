#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

struct edge{
	int to;
	int cost;
};

int V;
vector<edge> g[100100];
int dist[100100];

// O(ElogV)
void dijkstra(int s){
	// P<最短距離, 頂点番号>
	priority_queue< P, vector<P> , greater<P>> que;
	fill(dist, dist+V, 1002003004);

	dist[s] = 0;
	que.push({0,s});

	while(!que.empty()){
		P p = que.top();
		que.pop();
		int nv = p.second;
		if(dist[nv] < p.first) continue;

		for(auto e: g[nv]){

            if (dist[e.to] > dist[nv] + e.cost) {
                dist[e.to] = dist[nv] + e.cost;
                que.push(P(dist[e.to], e.to));
            }

        }
    }
}

int main(){
	cin >> V;
	int E; cin >> E; int r; cin >> r;

	rep(i,E){
		int s, t, d; cin >> s >> t >> d;
		edge e = {t, d};
		g[s].push_back(e);
	}

	dijkstra(r);

	rep(i,V){
		if(dist[i] != 1002003004){
			cout << dist[i] << endl;
			continue;
		}
		cout << "INF" << endl;
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
using namespace std;
typedef long long int ll;

struct Edge{
	int to; ll dist;
	Edge(){}
	Edge(int to,ll dist):to(to),dist(dist){}
};

template <class E>
using Graph = vector<vector<E>>;
 
template<class D, D INF>
struct Dijkstra {
    vector<D> res; //res[i] = sからiまでの最短距離
    
    template<class E>
    Dijkstra(const Graph<E> &g, int s) {
        int V = (int)g.size();
        res = vector<D>(V, INF);
        
        using P = pair<D, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, s));
        res[s] = 0;
        while (!q.empty()) {
            P p = q.top(); q.pop();
            if (res[p.second] < p.first) continue;
            for (E e: g[p.second]) {
                if (p.first+e.dist < res[e.to]) {
                    res[e.to] = p.first+e.dist;
                    q.push(P(res[e.to], e.to));
                }
            }
        }
    }
};

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n,m,r; cin >> n >> m >> r;
	Graph<Edge> g(n);
	for(int i=0;i<m;i++){
		int a,b,c; cin >> a >> b >> c;
		g[a].push_back(Edge(b,c));
	}
	Dijkstra<ll,(ll)1e15> di(g,r);
	for(int i=0;i<n;i++){
		if(di.res[i]==1e15){
			cout << "INF" << endl;
		}
		else{
			cout << di.res[i] << endl;
		}
	}
}

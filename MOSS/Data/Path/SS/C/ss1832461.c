#include <bits/stdc++.h>
using namespace std;

#define INF 1e+9

struct Edge{
	  int s,t,w;
	  Edge(int si, int ti, int wi){
			s = si; t = ti; w = wi;
	  }
	  bool operator > (const Edge& e) const {
			return w > e.w;
	  }

};
typedef vector<vector<Edge> > AdjList;

struct state{
	  int v, w;
	  state(int vi, int wi){ v = vi; w = wi; }
	  bool operator > (const state& tgt) const {
			return w > tgt.w;
	  }
};

vector<int> dijk(int s, AdjList& G){
	  priority_queue<state,vector<state>, greater<state> > q;
	  vector<int> used(G.size(),INF);

	  q.push( state(s,0) );
	  while( q.size() ) {
			state corr = q.top(); q.pop();
			if(used[corr.v] != INF) continue;
			
			used[corr.v] = corr.w;
			// if(used[t] != -1) break;
			
			for(Edge e : G[corr.v])
				  if(used[e.t] == INF)
						q.push( state(e.t, corr.w + e.w) );
	  }
	  return used;
}

int main(){

	  int V,E,r; cin >> V >> E >> r;
	  
	  AdjList G(V);
	  for(int i=0; i<E; i++){
			int s,t,d; cin >> s >> t >> d;
			G[s].push_back(Edge(s,t,d));
	  }
	  vector<int> stlen = dijk(r,G);
	  for(int i=0; i<V; i++)
			if(stlen[i] != INF)
				  cout << stlen[i] << endl;
			else
				  cout << "INF" << endl;
			

}

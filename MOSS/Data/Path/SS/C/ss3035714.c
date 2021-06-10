#include <bits/stdc++.h> 

using namespace std;

#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))

const int INF_32 = -1 + (1 << 30);

template<class Abel> struct D_Graph {
	int V,E;
	bool **exist;
	vector<vector<pair<int,Abel>>> adj;
	vector<vector<pair<int,Abel>>> adj_inv;
	
	D_Graph(int V_size = 0) { init(V_size); }
	
	void init(int V_size) {
		V = V_size, E = 0;
		
		/*exist = (bool**)malloc(sizeof(bool*) * (V + 1));
		for(int i = 0; i <= V; ++i){
			exist[i] = (bool*)malloc(sizeof(bool) * (V + 1));
			fill(exist[i],exist[i] + V + 1,0);
		}*/
		
		adj.clear(); 
		adj_inv.clear();
		adj.resize(V + 1);
		adj_inv.resize(V + 1);
		adj[0].resize(V);
		for(int i = 1; i <= V; ++i){
			adj[0][i - 1] = {i,0};
			//exist[0][i] = 1;
			//adj[i].reserve(min(V,1000));
			//adj_inv[i].reserve(min(V,1000));
		}
	}
	
	int deg_out(int v) { return adj[v].size(); }
	
	int deg_in(int v) { return adj_inv[v].size(); }
	
	bool is_leaf(int v) { return deg_out(v) == 0; }
	
	bool is_root(int v) { return deg_in(v) == 0; }
	
	void add_edge(int from, int to, Abel cost = 1) {
		adj[from].push_back({to,cost});
		adj_inv[to].push_back({from,cost});
		//exist[from][to] = 1;
		++E;
	}
	
	void sort_edge(){
		for(int i = 0; i <= V; ++i) sort_edge(i);
	}
	
	void sort_edge(int v){
		sort(begin(adj[v]),end(adj[v]));
		sort(begin(adj_inv[v]),end(adj_inv[v]));
	}
	
	void dijkstra(vector<Abel> &dist, int src, Abel dist_max = INF_32){
		dist.clear();
		dist.resize(V + 1);
		fill(begin(dist),end(dist),dist_max);
		priority_queue<pair<Abel,int>,vector<pair<Abel,int>>,greater<pair<Abel,int>>> que;
		que.push({0,src});
		while(!que.empty()){
			int d = que.top().first;
			int v = que.top().second;
			que.pop();
			if(dist[v] <= d) continue;
			dist[v] = d;
			for(auto e : adj[v]) que.push({e.second + d,e.first});
		}
	}
	
	/*bool is_cyclic(){
		vector<int> s;
		return !tsort(s);
	}
	
	bool tsort(vector<int> &seq, bool idx_ord = 0) {
		seq.clear();
		seq.reserve(V + 1);
		
		vector<int> in(V + 1);
		for(int i = 0; i <= V; ++i) in[i] = deg_in(i);
		
		stack<int> rt;
		rt.push(0);
		
		while(!rt.empty()){
			int r = rt.top();
			rt.pop();
			for(auto e : adj[r]){
				int v = e.first;
				if(r) --in[v];
				if(!in[v]){
					rt.push(v);
					if(idx_ord){
						auto pos = begin(seq);
						bool det = 0;
						for(auto i = begin(seq); i < end(seq); ++i){
							if(!det && v > *i) ++pos;
							else det = 1; 
							if(exist[*i][v]){
								pos = i + 1;
								det = 0;
							}
						}
						seq.insert(pos,v);
					}else{
						seq.push_back(v);
					}
				}
			}
		}
		
		if(seq.size() == V) return 1;
		return 0;
	}*/
};


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int V,E,r;
	cin>>V>>E>>r;
	D_Graph<int> G(V);
	int s,t,d;
	rep(i,E){ cin>>s>>t>>d; G.add_edge(++s,++t,d); }
	vector<int> dist;
	G.dijkstra(dist,++r);
	rep(i,V){ if(dist[i + 1] < INF_32) cout<<dist[i + 1]<<'\n'; else cout<<"INF\n"; }
}




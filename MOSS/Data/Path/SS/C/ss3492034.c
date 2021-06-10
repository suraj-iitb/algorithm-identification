#include <iostream>
#include <vector>
#include <queue>
#include <limits>	

using namespace std;

const long INFINITE = numeric_limits<long>::max();

struct v_type{
	int id;
	long d;
	v_type(int id): id(id), d(INFINITE){} 
	void display(){
		if(d == INFINITE){
			cout << "INF" << endl;
		}else{
			cout << d << endl;
		}
	}
};

class Graph{
	vector<v_type> v_list;
	vector<vector<pair<int, long>>> adj_list;
	int V;
	int E;
public:
	Graph(int V, int E, vector<pair<pair<int, int>, long>> edges){
		this->V = V;
		this->E = E;
		for(auto i = 0; i < V; ++i) v_list.push_back({i});
		adj_list = vector<vector<pair<int, long>>>(V, vector<pair<int, long>>());
		for(auto edge: edges){
			int src = edge.first.first;
			int dest = edge.first.second;
			long d = edge.second;
			adj_list[src].push_back({dest, d});
		}
	}

	void dijsktra(int r){
		v_list[r].d = 0.0;
		auto comp = [](v_type u, v_type v){ return u.d > v.d; };
		priority_queue<v_type, vector<v_type>, decltype(comp)> q(comp);
		q.push(v_list[r]);

		while(!q.empty()){
			v_type top = q.top();
			q.pop();
			int src = top.id;
			for(auto dest_p: adj_list[src]){
				int dest = dest_p.first;
				long d = dest_p.second;
				if(v_list[dest].d > v_list[src].d + d){
					v_list[dest].d = v_list[src].d + d;
					q.push(v_list[dest]);
				}
			}
		}
		for(auto i = 0; i < V; ++i) v_list[i].display();
	}
};

int main(){
	int V, E;
	int r;
	cin >> V >> E >> r;
	vector<pair<pair<int, int>, long>> edges;
	for(auto i = 0; i < E; ++i){
		int src, dest;
		long d;
		cin >> src >> dest >> d;
		edges.push_back({{src, dest}, d});
	}
	Graph g(V, E, edges);
	g.dijsktra(r);
}	

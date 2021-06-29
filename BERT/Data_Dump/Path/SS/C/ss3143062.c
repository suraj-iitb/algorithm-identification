#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif

typedef std::pair<int, int> P; //first:最短距離，second:頂点番号

class Edge{
public:
	int to;
	int cost;

	Edge(){
		return;
	}
	~Edge(){
		return;
	}
};

#define MAX_COST (1000000000)

int main(int argc, char **argv){
	int n, m, r;
	std::vector<std::vector<Edge> > G;
	std::vector<long> min_cost;
	std::priority_queue<P, std::vector<P>, std::greater<P> > que;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
	//FILE *fp = fopen("test.txt", "r");
#endif
	
	
#if INPUT_FROM_FILE
	ifs >> n >> m >> r;
#else
	std::cin >> n >> m >> r;
#endif
	G.resize(n);

	for(int i = 0; i < m; i++){
		int s, t, d;
		Edge edge;

#if INPUT_FROM_FILE
		ifs >> s >> t >> d;
#else
		std::cin >> s >> t >> d;
#endif

		edge.to = t;
		edge.cost = d;
		G[s].push_back(edge);
	}

	min_cost.resize(n, MAX_COST);
	min_cost[r] = 0;
	que.push(P(0, r));

	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(min_cost[v] < p.first) continue;
		
		for(int i = 0; i < G[v].size(); i++){
			Edge &e = G[v][i];

			if(min_cost[e.to] > min_cost[v] + e.cost){
				min_cost[e.to] = min_cost[v] + e.cost;
				que.push(P(min_cost[e.to], e.to));
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(min_cost[i] == MAX_COST){
			std::cout << "INF" << std::endl;
		}
		else{
			std::cout << min_cost[i] << std::endl;
		}
	}
	return 0;
}

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

struct Info{
	Info(int arg_to,int arg_cost){
		to = arg_to;
		cost = arg_cost;
	}
	bool operator<(const struct Info &arg) const{
			return cost > arg.cost;
	};
	int to,cost;
};


int main(){

	int V,E,start;
	scanf("%d %d %d",&V,&E,&start);

	int *min_cost = new int[V];
	for(int i = 0; i < V; i++)min_cost[i] = BIG_NUM;

	vector<Info> Edges[V];

	min_cost[start] = 0;

	int from,to,cost;
	for(int i = 0; i < E; i++){
		scanf("%d %d %d",&from,&to,&cost);
		Edges[from].push_back(Info(to,cost));
	}

	priority_queue<Info> Q;

	for(int i = 0; i < Edges[start].size(); i++){
		if(min_cost[Edges[start][i].to] > Edges[start][i].cost){
			min_cost[Edges[start][i].to] = Edges[start][i].cost;
			Q.push(Info(Edges[start][i].to, Edges[start][i].cost));
		}
	}

	int min_index;

	while(!Q.empty()){
		if(Q.top().cost > min_cost[Q.top().to]){
			Q.pop();
		}else{
			min_index = Q.top().to;
			Q.pop();
		}

		for(int i = 0; i < Edges[min_index].size(); i++){
			if(min_cost[Edges[min_index][i].to] > min_cost[min_index] + Edges[min_index][i].cost){
				min_cost[Edges[min_index][i].to] = min_cost[min_index] + Edges[min_index][i].cost;
				Q.push(Info(Edges[min_index][i].to,min_cost[Edges[min_index][i].to]));
			}
		}
	}

	for(int i = 0; i < V; i++){
		if(min_cost[i] == BIG_NUM)printf("INF\n");
		else{
			printf("%d\n",min_cost[i]);
		}
	}


	return 0;
}

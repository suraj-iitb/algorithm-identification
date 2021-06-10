#include <bits/stdc++.h>
using namespace std;

const int INF = 2.1e9;

//Graph/Template
template<class T>
struct Edge{
	int from,to;
	T cost;
	Edge(int to,T cost) : to(to),cost(cost){}
	Edge(int from,int to,T cost) : from(from),to(to),cost(cost){}
};

template<class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using Graph = vector<vector<int>>;
template<class T>
using Matrix = vector<vector<T>>;

//Graph/WarshallFloyd
template<class T>
void warshallFloyd(Matrix<T> &G){
	for(int k = 0;k < G.size();k++){
		for(int i = 0;i < G.size();i++){
			for(int j = 0;j < G.size();j++){
				if(G[i][k] == INF || G[k][j] == INF) continue;
				G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
			}
		}
	}
}

signed main(){
	int n,m;
	scanf("%d %d",&n,&m);
	Matrix<int> G(n,vector<int>(n,INF));
	for(int i = 0;i < n;i++) G[i][i] = 0;
	for(int i = 0;i < m;i++){
		int s,t,d;
		scanf("%d %d %d",&s,&t,&d);
		G[s][t] = min(G[s][t],d);
	}
	warshallFloyd(G);
	for(int i = 0;i < n;i++){
		if(G[i][i] < 0){
			printf("NEGATIVE CYCLE\n");
			return 0;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(j) printf(" ");
			if(G[i][j] == INF) printf("INF");
			else printf("%d",G[i][j]);
		}
		printf("\n");
	}
}


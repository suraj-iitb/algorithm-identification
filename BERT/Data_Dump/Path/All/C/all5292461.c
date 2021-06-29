#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAX_V = 100, MAX_E = 9900;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

long long G[MAX_V][MAX_V];
void init_G(int V){
	for (int u = 0; u < V; ++u)
		for (int v = 0; v < V; ++v){
			if(u != v)	G[u][v] = INF;
		}
}
void add_edge(int u,int v,int c){
	G[u][v] = min(G[u][v],(long long)c);
}

bool floyd_warshall(int V){
	//return false;
	for (int w = 0; w < V; ++w){
		for (int u = 0; u < V; ++u)
			for (int v = 0; v < V; ++v){
				if(G[u][w] == INF || G[w][v] == INF)	
					continue;

				G[u][v] = min(G[u][v],G[u][w] + G[w][v]);
			}
		}

	for (int v = 0; v < V; ++v)
		if(G[v][v] < 0)
			return true;

	return false;
}

const char NEG_CYCLE[] = "NEGATIVE CYCLE";

int main(){
	int V,E;	scanf("%d%d",&V,&E);
	init_G(V);
	for (int i = 0; i < E; ++i){
		int s,t,d;
		scanf("%d%d%d",&s,&t,&d);
		add_edge(s,t,d);
	}
	if(floyd_warshall(V))	puts(NEG_CYCLE);
	else{
		for (int u = 0; u < V; ++u){
			for (int v = 0; v < V; ++v){
				if(G[u][v] == INF)	printf("INF%c"," \n"[v==V-1]);
				else				printf("%lld%c",G[u][v], " \n"[v==V-1]);
			}
		}
	}
}



#include<cstdio>
#include<algorithm> 
#include<vector> 
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
const int max_n=100;
const int max_v=max_n,max_e=9900;
const long long INF= 0x3f3f3f3f3f3f3f3fLL;

long long G[max_v][max_v];
void init_G(int V){
	for(int i=0;i<V;++i)
		for(int j=0;j<V;++j)
			if(i!=j)	G[i][j]=INF;
		
}

void add_edge(int u,int v,int w){
	G[u][v]=min(G[u][v],(long long)w);
}

bool floyd_warshall(int V){
	for(int w=0;w<V;w++)
		for(int u=0;u<V;u++)
			for(int v=0;v<V;v++){
				if(G[u][w]==INF||G[w][v]==INF) continue;
				G[u][v]=min(G[u][v],G[u][w]+G[w][v]);
			}
		for(int v=0;v<V;v++)
			if(G[v][v]<0)
			return true;
			
		return false;		
}

const char NEG_CYCLE[] = "NEGATIVE CYCLE";

int main(){
	int V,E;scanf("%d%d",&V,&E);
	init_G(V);
	for(int i=0;i<E;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		}
		if(floyd_warshall(V))
			puts(NEG_CYCLE);
	else{
		for (int u = 0; u < V; ++u){
			for (int v = 0; v < V; ++v){
				if(G[u][v] == INF)	printf("INF%c"," \n"[v==V-1]);
				else				printf("%lld%c",G[u][v], " \n"[v==V-1]);
			}
		}}
}


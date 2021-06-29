#include <bits/stdc++.h>

using namespace std;
const int maxn = 10000;
int n,q;
int d[maxn];
int pre[maxn];
struct edge_t{
	int start;
	int end;
	int weight;
};
edge_t edge[maxn];
bool bellmanford(int r){
	//init
	for(int i=0;i<n;i++){
		d[i] = INT_MAX;
	}
	d[r] = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<q;j++){
			int u = edge[j].start;
			int v = edge[j].end;
			int w = edge[j].weight;
			if(d[u] == INT_MAX) continue;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
			}
		}
	}
	//negative cycle check
	for(int j=0;j<q;j++){
		int u = edge[j].start;
		int v = edge[j].end;
		int w = edge[j].weight;
		if(d[u] == INT_MAX) continue;
		if(d[v] > d[u] + w){
			return false;
		}		
	}
	return true;
}
void grl_1_c(){
	int r;
	scanf("%d %d",&n,&q);
	for(int i=0;i<q;i++){
		int s,t,d0;
		scanf("%d %d %d",&s,&t,&d0);
		edge[i].start = s;
		edge[i].end = t;
		edge[i].weight = d0;
	}
	bool flag = true;
	for(int i=0;i<n;i++){
		if(!bellmanford(i)){
			printf("NEGATIVE CYCLE\n");
			flag = false;
			break;
		}
	}
	if(flag){
		for(int i=0;i<n;i++){
			bellmanford(i);
			for(int j=0;j<n;j++){
				if(j>0) printf(" ");
				if(d[j] == INT_MAX) printf("INF");
				else printf("%d",d[j]);
			}
			printf("\n");
		}
	}
}
//#define LOCAL
int main(int argc, char** argv) {
	#ifdef LOCAL
		FILE *fin,*fout;
		fin = freopen("in.txt","r",stdin);
		fout = freopen("out.txt","w",stdout);
	#endif
	grl_1_c();
	//printf("Time used = %.5f ms\n", (double)clock() / CLOCKS_PER_SEC *1000);
	return 0;
}

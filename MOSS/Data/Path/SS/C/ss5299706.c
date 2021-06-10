#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000;
vector<pair<int,int> > G[maxn];
int d[maxn],vis[maxn];
int n,q;
void dijstra(int r){
	for(int i=0;i<n;i++) {
		d[i] = INT_MAX;
		vis[i] = 0;
	}
	d[r] = 0;
	vis[r] = -1;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(d[r],r));
	while(!pq.empty()){
		int shortest = INT_MAX;
		int u = -1;
		pair<int,int> tt = pq.top();
		pq.pop();
		u = tt.second;
		if(d[u] < tt.first *(-1) ) continue;
		vis[u] = 1;
		for(int v=0;v<G[u].size();v++){
			int t = G[u][v].first;
			if(d[t] > d[u] + G[u][v].second && vis[t] != 1){
				d[t] = d[u] + G[u][v].second;
				vis[t] = -1;
				pq.push(make_pair(d[t]*(-1),t));
			}
		}
	}
}
void grl_1_a(){
	int r;
	scanf("%d %d %d",&n,&q,&r);
	for(int i=0;i<q;i++){
		int s,t,d0;
		scanf("%d %d %d",&s,&t,&d0);
		G[s].push_back(make_pair(t,d0));
	}
	dijstra(r);
	for(int i=0;i<n;i++){
		if(d[i] == INT_MAX) printf("INF\n");
		else printf("%d\n",d[i]);
	}
}
//#define LOCAL
int main(int argc, char** argv) {
	#ifdef LOCAL
		FILE *fin,*fout;
		fin = freopen("in.txt","r",stdin);
		fout = freopen("out.txt","w",stdout);
	#endif
	grl_1_a();
	//printf("Time used = %.5f ms\n", (double)clock() / CLOCKS_PER_SEC *1000);
	return 0;
}

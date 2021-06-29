#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,s;
struct point{
	int v;
	ll w;
	bool operator<(const point&p)const{
		return w>p.w;
	}
};
ll d[100005];
bool vis[1000005];
ll inf=1e12;
vector<point>e[100005];
void solve(){
	fill(d,d+n+1,inf);
	d[s]=0;vis[s]=1;
	priority_queue<point> q;
	for(int i=0;i<e[s].size();i++)q.push(e[s][i]);
	int k=1;
	while(k!=n&&!q.empty()){
		point p=q.top();q.pop();
		if(!vis[p.v]){
			d[p.v]=p.w;
			vis[p.v]=1;
			for(int i=0;i<e[p.v].size();i++)q.push({e[p.v][i].v,e[p.v][i].w+p.w});
			k++;
		}		
	}
	for(int i=0;i<n;i++){
		if(d[i]>=inf){
			cout<<"INF"<<endl;
		}else cout<<d[i]<<endl;
	}
}
int main(){
	cin>>n>>m>>s;
	int u,v,w;
	while(m--){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
	}
	solve();
	return 0;
}

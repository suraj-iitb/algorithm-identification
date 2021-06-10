#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> int_pair;
typedef pair<ll,ll> ll_pair;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define MAX_V 100001
#define INF (1e9+1)
struct edge{
	int to,cost;
};
int V,E,r,a,b,c;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(){
	FOR(i,0,MAX_V)d[i]=INF;
	d[r]=0;
	priority_queue< pair<int,int> > Q;
	Q.push( make_pair(0,r) );
	while(Q.size()){
		pair<int,int> p=Q.top();
		Q.pop();
		int cost=-p.first,es=p.second;
		if(cost>d[es])continue;
		FOR(i,0,G[es].size()){
			edge e=G[es][i];
			int to=e.to;
			int newcost=cost+e.cost;
			if(newcost<d[to]){
				d[to]=newcost;
				Q.push(make_pair(-d[to],to));
			}
		}
	}
	FOR(i,0,V){
		if(d[i]==INF)cout<<"INF"<<endl;
		else cout<<d[i]<<endl;
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>V>>E>>r;
	FOR(i,0,E){
		cin>>a>>b>>c;
		G[a].push_back((edge){b,c});
	}
	dijkstra();
	return 0;
}


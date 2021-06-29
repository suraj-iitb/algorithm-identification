#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb(a) push_back(a)
#define vi vector<int>
#define vvi vector<vi>
#define P pair<int,int>
#define all(vec) (vec.begin()),(vec.end())
#define ll long long;
#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x;
#define bit(n) (1<<(n))

#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define REP3(i, m, n) for(int i = m, i##_len=(n);i < i##_len;i++)
#define FORVEC(i, v) for(int i = 0;i < sz(v);i++)

#define MAX_V 100000
struct edge {int to,cost;};
int V,E;
vector<edge> G[MAX_V];
int d[MAX_V];
void dijkstra(int start){
	priority_queue<P,vector<P>,greater<P>> Q;
	fill(d,d+V,INF);
	d[start]=0;
	Q.push(make_pair(0,start));
	while(!Q.empty()){
		P p=Q.top();
		Q.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		FORVEC(i,G[v]){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				Q.push(make_pair(d[e.to],e.to));
			}
		}
	}
}

int main(){
	cin>>V>>E;
	int r;
	int s,t,D;
	cin>>r;
	REP(i,E){
		cin>>s>>t>>D;
		G[s].push_back((edge){t,D});
	}

	dijkstra(r);
	REP(i,V){
		if(d[i]==INF)cout<<"INF\n";
		else cout<<d[i]<<"\n";
	}

	return 0;
}

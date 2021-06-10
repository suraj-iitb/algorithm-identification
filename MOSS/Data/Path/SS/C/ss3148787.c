#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_VAL 100000
#define INF 4123456789123456

typedef long long ll;
typedef pair<ll,ll> P;

struct edge{ll to, cost;};

vector<edge> G[MAX_VAL];
ll d[MAX_VAL], V;

void dijkstra(ll s){
	priority_queue<P,vector<P>,greater<P>> q;
	fill(d,d+V, INF);
	
	d[s] = 0;
	q.push(P(0,s));
	
	while(!q.empty()){
		P p = q.top();q.pop();
		ll v = p.second;
		
		if(d[v] < p.first) continue;
		
		for(edge e : G[v]){
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
	
	
}

int main(){
	struct edge e;
	ll E, r, s;
	
	cin>>V>>E>>r;
	
	for(int i = 1; i <= E; i++){
		cin>>s>>e.to>>e.cost;
		G[s].push_back(e);
	}
	
	dijkstra(r);
	
	for(int i = 0; i < V; i++)
		cout<<(d[i]==INF?"INF":to_string(d[i]))<<endl;
	
	return 0;
}

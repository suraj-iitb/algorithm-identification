#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to, cost;};
#define INF 1000000001

int V,E;
vector<edge> G[100005];
int d[100005];

void dijkstra(int s){
	priority_queue<P, vector<P>,greater<P> > que;
	for(int i=0;i<V;i++)d[i]=INF;
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

int main(void){
	int r,s;edge e;
	cin>>V>>E>>r;
	for(int i=0;i<E;i++){
		cin>>s>>e.to>>e.cost;
		G[s].push_back(e);
	}
	dijkstra(r);
	for(int i=0;i<V;i++){
		if(d[i]==INF)cout<<"INF\n";
		else cout<<d[i]<<endl;
	}
	
	return 0;
}


#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;

struct edge{
	int to;
	int cost;
};

typedef vector<vector<struct edge>> AdjList;
AdjList graph;
typedef pair<int,int> P;
const int INF = 1e9;
vector<int> dist;
vector<int> prever;

void dijkstra(int n,int s){
	dist = vector<int>(n,INF);
	prever = vector<int>(n-1);
	dist[s] = 0;
	priority_queue<P,vector<P>,greater<P>> que;
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if( dist[v] < p.first){
			continue;
		}
		for(int i = 0; i < graph[v].size(); i++){
			struct edge e = graph[v][i];
			if( dist[e.to] > dist[v] + e.cost){
				dist[e.to] = dist[v] + e.cost;
				//prever[e.to] = v;
				que.push(P(dist[e.to],e.to));
			}
		}
	}
}


int main()
{
	int V,E,r;
	cin>>V>>E>>r;
	graph = vector<vector<edge>>(V);
	for(int i = 0; i < E; i++){
		int s,t,d;
		cin>>s>>t>>d;
		edge e;
		e.to = t;
		e.cost = d;
		graph[s].push_back(e);
	}
	dijkstra(V,r);
	for(int i = 0; i < V; i++){
		if(dist[i] == INF){
			cout<<"INF"<<endl;
		}else{
			cout<<dist[i]<<endl;
		}
	}
	return 0;
}



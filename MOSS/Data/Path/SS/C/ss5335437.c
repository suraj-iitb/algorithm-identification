#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <iterator>
#include <queue>
#define ll long long int
using namespace std;

struct edge{
	int to,cost;
};
typedef vector<vector<edge> > AdjList;
AdjList graph;
typedef pair<int,int> P;
const int INF = 1e9;
vector<int> dist;

void dijkstra(int n,int s){
	dist = vector<int>(n,INF);
	dist[s] = 0;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,s));
	while( !que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if( dist[v] < p.first){
			continue;
		}
		for(int i = 0; i < graph[v].size(); i++){
			edge e = graph[v][i];
			if( dist[e.to] > dist[v] + e.cost){
				dist[e.to] = dist[v] + e.cost;
				que.push(P(dist[e.to],e.to));
			}
		}
	}
}

int main()
{
	int n,e,r;
	cin>>n>>e>>r;
	graph = vector<vector<edge> >(n);
	for(int i = 0; i < e; i++){
		int s,t,d;
		cin>>s>>t>>d;
		edge temp;
		temp.to = t;
		temp.cost = d;
		graph[s].push_back(temp);
	}
	dijkstra(n,r);
	for(int i = 0; i < n; i++){
		if( dist[i] == INF){
			cout<<"INF"<<endl;
		}else{
			cout<<dist[i]<<endl;
		}
	}
	return 0;
}



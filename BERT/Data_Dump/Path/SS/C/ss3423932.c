//AOJ GRL_4_B

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<ll,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e15;
const ll MAXN = 1e9;

vector<int> toporogical_sort(const vector<vector<int> > g){
	int n = g.size();
	vector<int> in_degree(n,0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			in_degree[g[i][j]]++;
		}
	}

	vector<int> res;
	stack<int> S;
	for(int i = 0; i < n; i++){
		if(in_degree[i]==0) S.push(i);
	}

	while(!S.empty()){
		int p = S.top();
		S.pop();
		res.push_back(p);
		for(int i = 0; i < g[p].size(); i++){
			in_degree[g[p][i]]--;
			if(in_degree[g[p][i]]==0) S.push(g[p][i]);
		}
	}

	return res;
}

vector<ll> dijkstra(const vector<vector<P> > g,const int r){
	int n = g.size();
	vector<ll> res(n,INF);
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,r));
	res[r]=0;
	while(!que.empty()){
		P x = que.top();que.pop();
		for(int i = 0; i < g[x.second].size(); i++){
			if(res[g[x.second][i].second] > x.first + g[x.second][i].first){
				res[g[x.second][i].second] = x.first + g[x.second][i].first;
				// g[x.second][i].first = x.first + g[x.second][i].first;
				que.push(P(res[g[x.second][i].second],g[x.second][i].second));
			}
		}
	}

	return res;
}

int main()
{
	int V,E,r;
	cin>>V>>E>>r;
	vector<vector<P> > g(V,vector<P>());
	for(int i = 0; i < E; i++){
		int a,b,d;
		cin>>a>>b>>d;
		g[a].push_back(P(d,b));
	}

	vector<ll> shortest_path = dijkstra(g,r);
	for(int i = 0; i < shortest_path.size(); i++){
		if(shortest_path[i]==INF) cout << "INF"<<endl;
		else cout << shortest_path[i] << endl;
	}

	return 0;
}

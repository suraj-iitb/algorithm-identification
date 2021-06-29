#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <string.h>
#define INF 1000000001

using namespace std;

ifstream in("sssp.in");

const int MAXV = 100005;
const int MAXM = 100005;

int v, e, s, x, y, c;
vector <pair<int, int> > g[MAXV];
int cost[MAXV];
priority_queue<pair <int, int> > q;

void dijkstra(){
	for(int i = 0; i < v; i++) 
		cost[i] = INF;

	cost[s] = 0;
	q.push(make_pair(s,0));

	while(!q.empty()){

		int node = q.top().first;
		int costt = q.top().second;

		q.pop();

    for(int i = 0; i < g[node].size(); i++){
    	pair<int, int> poss = g[node][i];
    	if(cost[poss.first] > poss.second - costt){
    		cost[poss.first] = poss.second - costt;
    		q.push(make_pair(poss.first, -cost[poss.first]));
    	}
		}
	}
}

int main(){	
	cin >> v >> e >> s;
	for(int i = 0; i < e; ++i){
		cin >> x >> y >> c;
		g[x].push_back(make_pair(y, c));
	}
	dijkstra();

	for(int i = 0; i < v; ++i){
		if(cost[i] == INF) 
			cout << "INF" << '\n';
		else 
			cout << cost [i] << '\n';
	}

  return 0;
}


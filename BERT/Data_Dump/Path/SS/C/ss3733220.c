#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<functional>
using namespace std;
#define LL long long
#define MOD 1000000007

int v,e,r,cost[100002];

vector<pair<int, int>>edge[100002];//node,cost
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > P;//cost,node

int main(){
	cin >> v >> e >> r;
	for(int i=0; i<v; i++) cost[i] = MOD;
	for(int i=0; i<e; i++){
		int s,t,d;
		cin >> s >> t >> d;
		edge[s].push_back(make_pair(t, d));
	}
	cost[r] = 0;
	P.push(make_pair(0, r));
	while(!P.empty()){
		pair<int, int> now = P.top();
		P.pop();
		for(int i=0; i<edge[now.second].size(); i++){
			if(cost[ edge[now.second][i].first ] > now.first + edge[now.second][i].second){
				cost[ edge[now.second][i].first ] = now.first + edge[now.second][i].second;
				P.push(make_pair(cost[ edge[now.second][i].first ], edge[now.second][i].first));
			}
		}
	}
	for(int i=0; i<v; i++){
		if(cost[i] == MOD) cout << "INF" <<endl;
		else cout << cost[i] << endl;
	}
	return 0;
}



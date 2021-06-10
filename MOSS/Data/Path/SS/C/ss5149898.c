#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define INT_MAX 1e9

int main(){
	int V,E,r;
	cin >> V >> E >> r;
	vector<int> ans(V,INT_MAX);
	vector<vector<int> > way(100001);
	vector<vector<int> > cost(100001);
	for(int i=0;i<E;i++){
		int s,t,d;
		cin >> s >> t >>d;
		way[s].push_back(t);
		cost[s].push_back(d);
		}
	queue<int> list;
	list.push(r);
	ans[r] = 0;
	while(!list.empty()){
		int cur = list.front();
		list.pop();
		for(int i=0;i<(int)way[cur].size();i++){
			if(ans[cur]+cost[cur][i] < ans[way[cur][i]]){
				list.push(way[cur][i]);
				ans[way[cur][i]] = ans[cur]+cost[cur][i];
				}
			}
		}
	for(auto v:ans){
		if(v==INT_MAX) cout << "INF\n";
		else cout << v <<"\n";
		}
	}


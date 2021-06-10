#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
const long long BIG = 1e18;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

vector<pair<ll, ll> > graph[100000];
ll dist[100000];

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > que;
	que.push(make_pair(0, start));

	while(!que.empty()){
		pair<ll, ll> p = que.top();
		que.pop();
		if (dist[p.second] < p.first) continue;
		for (auto x : graph[p.second]){
			if (dist[x.first] > dist[p.second] + x.second){
				dist[x.first] = dist[p.second] + x.second;
				que.push(make_pair(dist[x.first], x.first));
			}
		}
	}
}

int main(){
	ll v, e, r;
	cin >> v >> e >> r;

	for (int i = 0; i < e; i++){
		ll x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back(make_pair(y, z));
	}

	for (int i = 0; i < v; i++){
		dist[i] = BIG;
	}

	dijkstra(r);

	for (int i = 0; i < v; i++){
		if (dist[i] == BIG) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}

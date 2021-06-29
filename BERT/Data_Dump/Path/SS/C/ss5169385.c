#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
#define int long long
int n,m;

vector<pair<int,int> > con[100000+6]; 
bool vis[100006] = {};
long long dis[100006] = {};
#undef int
int main(){
	#define int long long
	cin >> n >> m;
	int r;
	cin >> r;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		con[u].push_back(make_pair(w,v));
	}
	for(int a = 0;a < n;a++) dis[a] = 5000000000000;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(mp(0,r));
	dis[r] = 0;
	while(pq.size()){
		int now = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (dis[now] < d) continue;
		vis[now] = 1;
		for(auto it:con[now]){
			if (!vis[it.second]){
				if (it.first + d < dis[it.second]){
					dis[it.second] = it.first + d;
					pq.push(mp(dis[it.second],it.second));
				}
			}
		}
	}
	for(int a = 0;a < n;a++){
		if (dis[a] == 5000000000000) cout << "INF\n";
		else cout << (dis[a]) << '\n';
	} 
}



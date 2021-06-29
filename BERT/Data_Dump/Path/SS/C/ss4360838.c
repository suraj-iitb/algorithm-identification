#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef pair<ll,ll> pll;
const int inf = 999999999;
const int nax = 2e6 + 7;
ll  n, m , s;
vector< pair< ll , ll > > gra[nax];
priority_queue<pll , vector<pll> , greater< pll > >pq;
ll dis[nax];
void shortest_path(){
    for(int i = 0 ; i < n ; i++)
		dis[i] = inf;
    pq.push({0 , s});
    dis[s] = 0;
    while(!pq.empty()){
        pll mini = pq.top();
        pq.pop();
        ll u = mini.second;
      //  ll wt = mini.first;
        for(auto it : gra[u]){
            ll v = it.first;
            ll vt = it.second;
            if(dis[v] > dis[u] + vt){
                dis[v] = dis[u] + vt;
                pq.push({dis[v] , v});
			}
        }
    }
}
int main(){
	dhoom;
    cin >> n >> m >> s;
    for(int i = 0 ; i < m ; i++){
        int u , v , wt;
        cin >> u >> v >> wt;
        gra[u].push_back({v, wt});
    //    gra[v].push_back({u,wt});
    }
    shortest_path();
    for(int i = 0 ; i < n ;i++){
		if(dis[i] == inf)
			cout << "INF" << endl;
		else 
			cout << dis[i] << endl;
    }
    return 0;
}



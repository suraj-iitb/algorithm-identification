#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;

int main() {
    int V, E, r;
    cin>>V>>E>>r;
    vector<vector<pair<int, int> > > edge(V);
    int s, t, d;
    for(int i=0;i<E;++i){
        cin>>s>>t>>d;
        edge[s].push_back(make_pair(t, d));
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    que.push(make_pair(0, r));
    pair<int, int> state;
    int dist[V];
    for(int i=0;i<V;++i){
        dist[i] = inf;
    }
    while(!que.empty()){
        state = que.top();que.pop();
        if(dist[state.se] < state.fi) continue;
        dist[state.se] = state.fi;
        for(int i=0;i<edge[state.se].size();++i){
            if(dist[edge[state.se][i].fi] == inf) que.push(make_pair(state.fi + edge[state.se][i].se, edge[state.se][i].fi));
        }
    }
    for(int i=0;i<V;++i){
        if(dist[i]==inf) cout<<"INF"<<endl;
        else cout<<dist[i]<<endl;
    }
}



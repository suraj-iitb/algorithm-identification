#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
vector<P> graph[110000];
int dist[110000];
const int INF = 1001001001001ll;
signed main(){
    int v,e,r;cin >> v >> e >> r;
    rep(i,e){
        int s,t,d;cin >> s>> t >> d;
        graph[s].emplace_back(t,d);
    }
    rep(i,110000)dist[i] = INF;
    priority_queue<P,vector<P>,greater<P>> q;
    q.emplace(0,r);
    dist[r] = 0;
    while(q.size()){
        auto hoge = q.top();q.pop();
        int now = hoge.second,d = hoge.first;
        if(dist[now] < d)continue;
        for(auto next:graph[now]){
            if(dist[next.first]  > dist[now] +next.second ){
                dist[next.first]  = dist[now] +next.second;
                q.emplace(dist[next.first],next.first);
            }
        }
    }
    rep(i,v){
        if(dist[i] == INF)cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    

    return 0;
}

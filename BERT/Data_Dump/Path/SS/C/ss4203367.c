#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<P> edge[1100000];

int v, e,r;
int s,t,d;

vector<Int> dijkstra(int start){
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<Int> dist(v, LINF);
    dist[start] = 0;
    pq.push(P(dist[start], start));

    while(!pq.empty()){
        auto p = pq.top();pq.pop();
        Int d = p.first;
        int from = p.second;
        if(dist[from] < d)continue;
        for(auto nxt: edge[from]){
            int to = nxt.first;
            Int c = nxt.second;
            if(dist[from] + c < dist[to]){
                dist[to] = dist[from] + c;
                pq.push(P(dist[to], to));
            }
        }
    }
    return dist;
}

int main(){
    cin >> v >> e >> r;
    for(int i = 0;i < e;i++){
        cin >> s >> t >> d;
        edge[s].push_back(P(t, d));
    }
    auto dist = dijkstra(r);
    for(int i = 0;i < v;i++){
        if(dist[i] == LINF)cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}

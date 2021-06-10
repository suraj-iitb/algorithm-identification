#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long long int llint;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int,int>
#define pl pair<ll,ll>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
const long double PI = acos(-1);
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int GCD(int x,int y){
    return y ? GCD(y,x%y) : x;
}
struct edge {ll to,cost;};
ll V,E,r,s,t,d;
ll dist[500050],dist2[500050];
vector<edge> G[500050];

void dijkstra(ll s){
    priority_queue<pl, vector<pl>, greater<pl> > que;
    fill(dist,dist+V,MM);
    dist[s] = 0;
    que.push(pl(0,s)); //first = distance, second = index

    while(que.size()){
        pl p = que.top();
        que.pop();
        ll pos = p.second;
        if(dist[pos] < p.first) continue;

        for(int i = 0; i < G[pos].size(); i++){
            edge e = G[pos][i];
            if(dist[e.to] > dist[pos] + e.cost){
                dist[e.to] = dist[pos]+e.cost;
                que.push(pl(dist[e.to],e.to));
            }
        }
    }
}

int main(){
    cin >> V >> E >> r;
    for(int i = 0; i < E; i++){
        cin >> s >> t >> d;
        G[s].push_back({t,d});
    }
    dijkstra(r);
    for(int i = 0; i < V; i++){
        if(dist[i] == MM) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}




#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
#include <cmath>
#include <string>
#include <string.h>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
#include <time.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 100000000000
#define MAX 200001
#define PI 3.141592653589793
const ll MOD = 1000000007;

/*clock_t start = clock();
clock_t end = clock();
const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
cout << time << endl;*/

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

#define MAX_V 200005

struct edge{
    int to,cost;
};

int V=MAX_V;
vector<edge> G[MAX_V];
ll d[MAX_V];


void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0, s));
    while (!que.empty()){
        P p = que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for (int i=0;i<G[v].size();i++) {
            edge e=G[v][i];
            if (d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    int V,E,r;
    cin >> V >> E >> r;
    rep(i,E){
        int s,t,d;
        cin >> s >> t >> d;
        G[s].push_back({t,d});
    }
    dijkstra(r);
    rep(i,V){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}

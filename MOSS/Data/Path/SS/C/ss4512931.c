#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// ダイクストラ法
// 参照：蟻本　p97
// O(mlogn)
struct edge{int to,cost;};
typedef pair<int,int> P; // firstは最短距離、secondは頂点の番号

int n; // 頂点の数
vector<edge> G[100010];
int d[100010];

void dijkstra(int s){
    priority_queue<P,vector<P>, greater<P>> que;
    fill(d,d+n,INF);
    d[s]=0;
    que.push(P(0,s));

    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main(){
    cin >> n;
    int m; // 辺の数
    cin >> m;
    int r;
    cin>>r;
    for (int i=0; i<m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {b, c};
        G[a].push_back(e);
    }
    dijkstra(r); // 頂点0からの距離を求める

    rep(i,n){
        if(d[i]==INF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
}


 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define sortr(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 2000001
#define vmax 10000
constexpr ll inf = 1000000000000;
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/

struct edge{
    int to,cost;
};

vector<vector<edge>> g;
vector<ll> d;
int V;

void dij(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    d.resize(V+1);
    fill(d.begin(),d.end(),inf);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(auto e:g[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }

}


int main() {
    int E,r,s,t,c;
    cin>>V>>E>>r;
    d.resize(V+1);
    g.resize(V+1);
    for(int i=0;i<E;i++){
        cin>>s>>t>>c;
        g[s].push_back({t,c});
    }

    dij(r);

    for(int i=0;i<V;i++){
        if(d[i]==inf){
            cout<<"INF"<<endl;
        }else{
            cout<<d[i]<<endl;
        }
    }
    return 0;
}













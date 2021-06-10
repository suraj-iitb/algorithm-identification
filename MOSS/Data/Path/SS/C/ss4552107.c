#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,ll>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

struct edge
{
    int to, cost;
};

int N = 1e5+5;
vector<ll> sum(N, INF);

void dijkstra(int x, vector<edge> G[]){
    priority_queue<int> q; 
    sum[x] = 0;
    q.push(x);
    while(!q.empty()){
        int v = q.top(); q.pop();


        for (auto& pp : G[v]) {
            if(sum[pp.to] > sum[v] + pp.cost) {
                sum[pp.to] = sum[v] + pp.cost;
            }else{
                continue;
            }
            q.push(pp.to);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int v, e, r;
    cin >> v >> e >> r;

    vector<edge> G[v];

    rep(i, e){
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(edge{t, d});
        //rG[t].push_back(edge{s, d});
    }

    dijkstra(r, G);
    //dijkstra(r, rG);

    for (int i = 0; i < v; ++i) {
        if(sum[i] == INF){
            cout << "INF" << "\n";
        }else{
            cout << sum[i] << "\n";
        }
    }


    return 0;
}


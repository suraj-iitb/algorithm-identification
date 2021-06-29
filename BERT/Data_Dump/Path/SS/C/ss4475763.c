#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;


int main() {
    ios_base::sync_with_stdio(false);


    int v,e,r;
    cin >> v >> e >> r;
    vector<vector<P>> g(v);
    rep(i,e) {
        int s,t,d;
        cin >> s >> t >> d;
        g[s].push_back(make_pair(t,d));
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(make_pair(0,r));
    vector<int> cost(v,-1);
    cost[r]=0;
    while (!pq.empty()) {
        P p=pq.top();
        int now=p.second,c=p.first;
        pq.pop();
        rep(j,g[p.second].size()) {
            int next=g[now][j].first;
            if (cost[next]==-1 || cost[next]>cost[now]+g[now][j].second) {
                cost[next]=cost[now]+g[now][j].second;
                pq.push(make_pair(cost[next],next));
            }
        }
    }
    rep(i,v) {
        if (cost[i]>=0) cout << cost[i] << endl;
        else cout << "INF" << endl;
    }
    

    return 0;   
}


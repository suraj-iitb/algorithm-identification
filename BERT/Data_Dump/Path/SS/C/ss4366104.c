
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define inf 1<<30

int n,m,s;
vector<pair<int,int> > e[MAX];

void solve(){
    priority_queue<pair<int,int> > pq;
    int d[MAX];
    fill(d,d+MAX,inf);
    d[s] = 0;
    pq.push(make_pair(0,s));
    while(pq.size()){
        pair<int,int> state = pq.top();
        int v = state.second,cost = -state.first;
        pq.pop();
        if(d[v] < cost)continue;
        
        for(int i=0;i<e[v].size();i++){
            int u = e[v][i].first;
            int n_cost = cost+e[v][i].second;
            if(n_cost<d[u]){
                d[u] = n_cost;
                pq.push(make_pair(-n_cost,u));
            }
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]==inf)cout<<"INF"<<endl;
        else         cout<<d[i]<<endl;
    }
}

int main(){
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back(make_pair(b,c));
    }
    solve();
}

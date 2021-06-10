
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 100010;
int n,m,sr;
vector<pair<int,ll>> grf[MAXN];
ll dis[MAXN];

void dijkastra(int src)
{
    memset(dis,63,sizeof dis);
    ll inf = dis[0];
    dis[sr]=0;
    // weigth  : node
    set<pair<ll,int>> q;
    q.insert({0,src});
    while(!q.empty()){
        ll len = q.begin()->first;
        int node = q.begin()->second;
        q.erase({len,node});
        for(auto nbr: grf[node]){
            // node : weight
            if( dis[nbr.first]> nbr.second + len ){
                q.erase({dis[nbr.first],nbr.first});
                dis[nbr.first] = nbr.second + len;            
                q.insert({dis[nbr.first],nbr.first});
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dis[i]==inf){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<dis[i]<<"\n";
        }
    }
}
int main() {
    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m>>sr;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        grf[a].push_back({b,c});
        // grf[b].push_back({a,c});
    }
    dijkastra(sr);
}

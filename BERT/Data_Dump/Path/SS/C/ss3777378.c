#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ft first
#define sd second
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

template <class U>
inline void dkstr(vector<vector<pair<int,U>>>& v,int n,int s,vector<U>& d,U inf){
    d.resize(n,inf);
    d[s]=0;
    vector<bool> vis(n);
    priority_queue<pair<U,int>,vector<pair<U,int>>,greater<>> pq;
    pq.emplace(0,s);
    while(!pq.empty()){
        pair<U,int> p=pq.top();pq.pop();
        U D=p.first;
        int i=p.second;
        if(vis[i]) continue;
        vis[i]=1;
        for(auto q:v[i]){
            if(vis[q.first]) continue;
            if(d[q.first]<=D+q.second) continue;
            d[q.first]=D+q.second;
            pq.emplace(D+q.second,q.first);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,s,a,b,w;
    cin>>n>>m>>s;
    vector<vector<pair<int,ll>>> v(n);
    fr(i,m){
        cin>>a>>b>>w;
        v[a].emplace_back(b,w);
    }
    vector<ll> d;
    dkstr(v,n,s,d,LONG_LONG_MAX);
    fr(i,n){
        if(d[i]<LONG_LONG_MAX) cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
    }
}

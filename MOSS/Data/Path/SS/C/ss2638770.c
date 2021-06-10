#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

vector<pint> vp[500001];
int d[100001];
int inf=1000100010;
int v;
int dijkstra(int st){
    priority_queue<pint,vector<pint>,greater<pint> > pq;
    rep(i,v) d[i]=inf;
    d[st]=0;
    pq.push(make_pair(0,st));
    while(!pq.empty()){
        pint pi=pq.top();pq.pop();
        int t=pi.second;
        for(vector<pint>::iterator it=vp[t].begin();it!=vp[t].end();++it){
            if(d[it->second]>d[t]+it->first){
                d[it->second]=d[t]+it->first;
                pq.push(make_pair(d[it->second],it->second));
            }
        }
    }
}
int main(){
    int e,r,s,t,ds;
    cin>>v>>e>>r;
    rep(i,e){
        cin>>s>>t>>ds;
        vp[s].pb(mp(ds,t));
    }
    dijkstra(r);
    rep(i,v){
        if(d[i]<inf) cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
    }
    return 0;
}

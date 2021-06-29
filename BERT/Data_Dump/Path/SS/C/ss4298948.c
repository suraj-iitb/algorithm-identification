#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

struct edge{
    int to;
    int cost;
};
int E,V;
vector<edge>G[100005];
int d[100005];

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>pq;
    fill(d,d+V,INF);
    d[s] = 0;
    pq.emplace(0,s);

    while(!pq.empty()){
        P p = pq.top();pq.pop();
        int v = p.second;
        if(d[v]<p.first)continue;

        rep(i,G[v].size()){
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                pq.emplace(d[e.to],e.to);
            }
        }
    }
}

int dp[105];
int main(){
    int s;
    cin>>V>>E>>s;
    rep(i,E){
        int a,b,c;cin>>a>>b>>c;
        edge e = {b,c};
        G[a].push_back(e);
    }
    dijkstra(s);
    rep(i,V){
        if(d[i]==INF)cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
}



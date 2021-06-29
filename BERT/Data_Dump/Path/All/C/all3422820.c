#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
ll INF = 1e15;
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,INF))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

template< typename T >
struct edge {
  ll src, to;
  T cost;

  edge(ll to, T cost) : src(-1), to(to), cost(cost) {}

  edge(ll src, ll to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator ll() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< ll > >;
template< typename T >
using Matrix = vector< vector< T > >;


template< typename T = ll >
void warshall_floyd(Matrix< T > &g)
{
  for(ll k = 0; k < g.size(); k++) {
    for(ll i = 0; i < g.size(); i++) {
      for(ll j = 0; j < g.size(); j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}
ll border = 1e13;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll v,e;
    cin>>v>>e;
    VEC2(g,v,v);
    FOR(i,0,e){
      ll in1,in2,c;
      cin>>in1>>in2>>c;
      g[in1][in2] = c;
    }
    warshall_floyd(g);
    ll flag = 0;
    FOR(i,0,v){
      if(g[i][i]<0)flag=1;
      g[i][i] = 0;
    }
    if(flag == 1) cout<<"NEGATIVE CYCLE"<<endl;
    else{

      FOR(i,0,v){
        FOR(j,0,v){
          if(g[i][j] > border) cout<<"INF";
          else cout<<g[i][j];
          if(j!=v-1)cout<<" ";
        }
        cout<<endl;
      }
    }
}


#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using VL=vector<ll>;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const long long INF =  999999999;

typedef pair<ll,ll> P;
struct edge{int to,cost;};
ll V,E,r;
vector<edge> e[100010];
ll d[100010];

//dickstra
int main(){
  priority_queue<P,vector<P>,greater<P>> que;
  cin >>V>>E>>r;
  REP(i,E){
    ll s,t,dist;
    cin>>s>>t>>dist;
    edge ed;
    ed.to=t;ed.cost=dist;
    e[s].push_back(ed);
  }

  fill(d,d+V,INF);
  d[r]=0;
  que.push(P(0,r));
  while(!que.empty()){
    P p=que.top();que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    REP(i,e[v].size()){

      if(d[e[v][i].to]>p.first+e[v][i].cost){
        d[e[v][i].to]=p.first+e[v][i].cost;
        que.push(P(d[e[v][i].to],e[v][i].to));
      }
    }
  }
  REP(i,V){
    if(d[i]==INF)cout<<"INF"<<endl;
    else cout<<d[i]<<endl;
  }
}


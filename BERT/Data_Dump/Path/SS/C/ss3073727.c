#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#include <limits>
#include <tuple>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pint;
typedef pair<double,int> pdi;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

float inf = std::numeric_limits<float>::infinity();
ll mod = 1e9+7;
ld epsilon = 1e-10;


vector<ld> weight;
ll N,E;
ll start;
ll xx[1005],yy[1005],tt[1005],rr[1005];
priority_queue<pdi,vector<pdi>,greater<pdi>> q;
vector<vector<pair<ll,ld>>> lines;

int search(ld w_0, ll &s){
  ll t;
  ld w;
  for (size_t i = 0; i < lines[s].size(); i++) {
    tie(t, w) = lines[s][i];
    w += w_0;
    if (weight[t]==-1 || weight[t] > w){
      q.push({w,t});
      weight[t] = w;
    }
  }
  return 0;
}

int dijkstra(int s){
  weight.resize(N,-1);
  weight[s] = 0;

  /* 実行部分(queueを回す)*/
  ll nq;
  ld wq;
  q.push({0,s}); /*スタート地点*/
  while (!q.empty()){
    tie(wq,nq) = q.top();
    q.pop();
    search(wq,nq);
  }

  for(ll w : weight){
    if(w<0){
      cout << "INF" << endl;
    }else{
      cout << w << endl;
    }
  }

}


int main(void) {
  cin >> N >> E >> start;

  lines.resize(N);

  ll s,t,d;
  REP(i,E){
    cin >> s >> t >> d;
    lines[s].push_back({t,d});
  }

  dijkstra(start);

}


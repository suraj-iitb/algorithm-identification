#include <iostream>
#include <vector>
using namespace std;

void shortest_path(int);

#define MAX_E 500000
#define MAX_V 100000

typedef long long ll;

const ll INF = 1e10;

struct edge {
  ll from; //何処から
  ll to;   //何処へ
  ll cost; //重み
};

edge es[MAX_E];  //辺

ll l[MAX_V];

ll V;  //頂点数
ll E;  //辺の数
ll r;  //始点

int main() {

  ll s, t, d;

  cin >> V >> E >> r;

  for(int i=0; i<E; ++i) {
    cin >> s >> t >> d;
    es[i].from = s;
    es[i].to = t;
    es[i].cost = d;
  }

  shortest_path(r);

  return 0;
}

void shortest_path(int s) {

  for(int i=0; i<V; ++i) l[i] = INF;

  l[s] = 0;

  while(true) {
    bool update = false;

    for(int i=0; i<E; ++i) {
      edge e = es[i];

      if(l[e.from] != INF && l[e.to] > l[e.from] + e.cost) {
        l[e.to] = l[e.from] + e.cost;
        update = true;
      }
    }
    if(!update) break;
  }

  for(int i=0; i<V; ++i) {
    if(l[i]==INF) cout << "INF" << endl;
    else cout << l[i] << endl;
  }
}


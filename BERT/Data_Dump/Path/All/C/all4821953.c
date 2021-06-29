#include <iostream>
#include <vector>
#include <cstdio>

#define INF 99999999999999999
#define V_MAX 100
#define E_MAX 9900

using namespace std;

struct edge {
  int start;
  int end;
  int cost;
};

bool flag;
long long int d[V_MAX][V_MAX];

void shortest_path(vector<edge> G, int v, int e, int r) {
  int cnt = 0;
  d[r][r] = 0;

  while(cnt < v) {
    bool update = false;
    for(int i = 0; i < e; i++) {
      edge E = G[i];
      if(d[r][E.start] != INF && d[r][E.end] > d[r][E.start] + E.cost) {
        d[r][E.end] = d[r][E.start] + E.cost;
        update = true;
      }
    }
    if( !update ) break;
    cnt++;
  }
  if(cnt == v) 
    flag = true;

}

void newline_or_space(int v, int j) {
  if(j != v - 1) {
    cout << " ";
  }
  else {
    cout << endl;
  }
}

int main(void) {
  int v, e;
  cin >> v >> e;
  edge E;
  vector<edge> G;

  for(int i = 0; i < e; i++) {
    cin >> E.start >> E.end >> E.cost;
    G.push_back(E);
  }

  for(int i = 0; i < v; i++) {
    for(int j = 0; j < v; j++) {
      d[i][j] = INF;
    }
  }
  
  flag = false;
  for(int i = 0; i < v; i++) {
    shortest_path(G, v, e, i);
    if( flag )
      break;
  }

  if( !flag ) {
    for(int i = 0; i < v; i++) {
      for(int j = 0; j < v; j++) {
        if(d[i][j] == INF) {
          cout << "INF";
          newline_or_space(v, j);
        }
        else {
          cout << d[i][j];
          newline_or_space(v, j);
        }
      }
    }
  } 
  else {
    cout << "NEGATIVE CYCLE" << endl;
  }
}

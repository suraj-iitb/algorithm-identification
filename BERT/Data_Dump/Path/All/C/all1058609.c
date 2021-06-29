#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;
const int MAX_V = 105;
const long INF = 1e18;

int V, E;

void disp(int f, long c[MAX_V][MAX_V]){
  if(!f) cout <<"NEGATIVE CYCLE" <<endl;
  else{
    REP(i, V){
      REP(j, V){
        if(c[i][j] == INF) cout <<"INF";
        else cout <<c[i][j];
        if(j != V - 1) cout <<" ";
      }
      cout <<endl;
    }
  }

}


bool warshall_floyd(long c[MAX_V][MAX_V]){
  REP(k, V)
    REP(i, V)
      REP(j, V)
        if(c[i][k] != INF && c[k][j] != INF) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
  REP(i, V) if(c[i][i] < 0) return false;
  return true;
}

int main() {
  cin >>V >>E;
  long c[MAX_V][MAX_V];
  REP(i, V) REP(j, V) c[i][j] = INF;
  REP(i, V) c[i][i] = 0;
  REP(i, E){
    int f, t, cost; cin >>f >>t >>cost;
    c[f][t] = cost;
  }
  bool f = warshall_floyd(c);
  disp(f, c);
  return 0;
}

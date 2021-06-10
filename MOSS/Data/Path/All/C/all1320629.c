#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
const ll INF = 5e9;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

vector<vector <ll>> worshallFloyd(vector<vector <ll>> d) {
  int V = d.size();
  for(int k = 0; k < V; k++) {
    for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
  }
  return d;
}

int main () {
  int V, E;
  cin >> V >> E;
  vector<vector <ll>> d(V, vector<ll>(V, INF));
  for(int i = 0; i < V; i++) d[i][i] = 0;
  for(int i = 0; i < E; i++) {
    int s, t, w;
    cin >> s >> t >> w;
    d[s][t] = w;
  }

  d = worshallFloyd(d);

  for(int i = 0; i < V; i++) if(d[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
  }
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(j != 0) cout << ' ';
      if(d[i][j] > 2e9) {
        cout << "INF";
      } else {
        cout << d[i][j];
      }
    }
    cout << endl;
  }
}

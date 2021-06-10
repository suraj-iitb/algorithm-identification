#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100;
static const long long INF = (1LL<<32);

long long d[MAX][MAX];

void init() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      if (i==j)
      {
        d[i][j] = 0;
      } else
      {
        d[i][j] = INF;
      }
    }
  }
}

void floyd(int V) {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      if (d[i][k] == INF)
      {
        continue;
      }
      for (int j = 0; j < V; j++) {
        if (d[k][j] == INF)
        {
          continue;
        }
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  /* 入力 */
  int V, E;
  cin >> V >> E;
  init();
  int s, t;
  long long w;
  for (int i = 0; i < E; i++) {
      cin >> s >> t >> w;
      d[s][t] = w;
      //d[t][s] = w;
  }

  /* 計算 */
  floyd(V);
  bool negative = false;
  for (int i = 0; i < V; i++) {
    if(d[i][i] < 0) {
      negative = true;
    }
  }

  /* 出力 */
  if (negative)
  {
    cout << "NEGATIVE CYCLE" << endl;
  }
  else
  {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (j)
        {
          cout << " ";
        }
        if (d[i][j] == INF)
        {
          cout << "INF";
        }
        else
        {
          cout << d[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}


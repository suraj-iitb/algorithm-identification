#include <bits/stdc++.h>
using namespace std;
#define pinf 0x7FFFFFFF

const int N = 101;
int graph[N][N];
int dist[N][N];

int main() {
  int n, m;
  int u, v, w;
  cin >> n >> m;

  //..initialise with all disconnected
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = pinf;
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    graph[u][v] = w;
  } 
  
  for (int i = 0; i < n; i++) {
    graph[i][i] = 0;
  } 

  //..copying the graph for processing
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] != pinf && dist[k][j] != pinf && dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      } 
    }
  } 

  //..cycle present when dist[i][i] < 0
  for (int i = 0; i < n; i++) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  //..print distance from each other
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) putchar(' ');
      if (dist[i][j] == pinf) {
        cout << "INF";
      } else {
        cout << dist[i][j];
      }
    }
    putchar('\n');
  }
  return 0;
}


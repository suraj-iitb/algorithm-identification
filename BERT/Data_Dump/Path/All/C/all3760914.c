#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;

// graph template
template<typename T>
class edge{
    public:
        int src, to; T cost;

        edge(int to, T cost): src(-1), to(to), cost(cost){}
        edge(int src, int to, T cost): src(src), to(to), cost(cost){}
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using AdjacencyList = vector<Edges<T>>;
template<typename T>
using Matrix = vector<vector<T>>;

template<typename T>
void warshall_floyd(Matrix<T> &g, T INF){
    for(int k = 0; k < (int)g.size(); k++){
        for(int i = 0; i < (int)g.size(); i++){
            for(int j = 0; j < (int)g.size(); j++){
                if(g[i][k] == INF or g[k][j] == INF) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(void){
  int V, E;
  scanf("%d %d", &V, &E);
  Matrix< int > mat(V, vector< int >(V, INT_MAX));
  for(int i = 0; i < V; i++) mat[i][i] = 0;
  for(int i = 0; i < E; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    mat[x][y] = z;
  }
  warshall_floyd(mat, INT_MAX);
  for(int i = 0; i < V; i++) {
    if(mat[i][i] < 0) {
      puts("NEGATIVE CYCLE");
      return 0;
    }
  }
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(j > 0) putchar(' ');
      if(mat[i][j] == INT_MAX) printf("INF");
      else printf("%d", mat[i][j]);
    }
    putchar('\n');
  }

  return 0;
}

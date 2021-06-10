#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MON 1000000007
#define INF (1LL<<60)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int dist[108][108];
Int n, m, x, y, w;
int main(){
  cin >> n >> m;
  for(Int i = 0;i < n;i++)
    for(Int j = 0;j < n;j++)
      dist[i][j] = INF;
  for(Int i = 0;i < m;i++){
    cin >> x >> y >> w;
    dist[x][y] =  w;
  }
  for(Int i = 0;i < n;i++)
    for(Int j = 0;j < n;j++)
      for(Int k = 0;k < n;k++)
	if(dist[j][i] != INF && dist[i][k] != INF)
	  dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);

  for(Int i = 0;i < n;i++){
    if(dist[i][i] < 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
    dist[i][i] = 0;
  }

  for(Int i = 0;i < n;i++){
    for(Int j = 0;j < n;j++){
      if(j)cout << " ";
      if(dist[i][j] == INF)cout << "INF";
      else cout << dist[i][j];

    }
    cout << endl;
  }
  
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (ll i = 0; i < N; i++)

int main()
{
  int V, E;
  cin >> V >> E;
  ll s[E], t[E], d[E];
  rep(i, E) cin >> s[i] >> t[i] >> d[i];
  ll INF = 1000000000000000;// 1ll << 50;
  ll dist[V][V];
  rep(i,V) rep(j, V) {if(i == j) dist[i][j] =0; else  dist[i][j] = INF;}
  rep(i,E){
    dist[s[i]][t[i]] = d[i];
  }
  rep(k, V){
    rep(i, V){
      rep(j, V){
     /*   if(i == 0 && k == 4 && j == 3) {
          cout << " i k j 0 4 3 -------------" << endl;
          cout << "dist[i][j] "  << dist[i][j] << "  dist[i][k] " <<  dist[i][k] << " dist[k][j] " << dist[k][j] << endl;
        }*/
         /* if(i ==1 && j == 0){
            cout << "before  ij 1->0 k " << k << " " << dist[i][k] << " " << dist[k][j] << " " << INF << endl;
          }
          */
        if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]){
         /* if(i ==1 && j == 0){
            cout << " ij 1->0 "<< dist[i][k] << " " << dist[k][j] << " " << INF << endl;
          }*/
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
  //    cout << "dist " << endl;
  //    rep(ii,V) { rep(jj, V) { cout << dist[ii][jj] << " | " ; } cout << endl;}
    }
  }
  rep(i,V) if(dist[i][i] < 0) {cout << "NEGATIVE CYCLE"<< endl; return 0;}
  rep(i,V){
    rep(j,V){
      if(dist[i][j] == INF) cout << "INF";
      else cout << dist[i][j];
      if(j < V-1) cout << " ";
    }cout << endl;
  }
}


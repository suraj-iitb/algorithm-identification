#include<iostream>
#include<cstdlib>

using namespace std;

typedef long long ll;
ll INF = 1e10;
ll llmin(ll a, ll b) { if (a < b) return a; else return b; }

int main() {
   int V, E;
   cin >> V >> E;
   ll dp[V][V];
   fill(dp[0], dp[V], INF);
   
   for (int i = 0; i < V; i++) {
      dp[i][i] = 0;
   }
   
   int s, t;
   ll d;
   for (int i = 0; i < E; i++) {
      cin >> s >> t >> d;
      dp[s][t] = d;
   }
   for (int k = 0; k < V; k++) {
      for (int i = 0; i < V; i++) {
         for (int j = 0; j < V; j++) {
            if (dp[i][k] == INF || dp[k][j] == INF) continue;
            dp[i][j] = llmin(dp[i][j], dp[i][k] + dp[k][j]);
         }
      }
   }
   for (int i = 0; i < V; i++) {
      if (dp[i][i] < 0) {
         cout << "NEGATIVE CYCLE" << endl;
         return 0;
      }
   }
   for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
         if (j == V - 1) {
            if (dp[i][j] == INF) cout << "INF" << endl;
            else cout << dp[i][j] << endl;
         } else {
            if (dp[i][j] == INF) cout << "INF ";
            else cout << dp[i][j] << " ";
         }
      }
   }
   return 0;
}


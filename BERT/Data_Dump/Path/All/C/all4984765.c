#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1LL<<60;
int main() {
   int N, M; cin >> N >> M;

   // dp[i][j] : iからjへの最短経路
   vector<vector<ll>> dp(N, vector<ll>(N, INF));

   for (int i=0; i<M; i++) {
      int s, t; ll d;
      cin >> s >> t >> d;
      dp[s][t] = d;
   }
   for (int i=0; i<N; i++) dp[i][i] = 0;

   // warshall-floyd
   for (int k=0; k<N; k++) {
   for (int i=0; i<N; i++) {
   for (int j=0; j<N; j++) {
      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
   }
   }
   }
   bool exist_negative_cycle = false;
   for (int i=0; i<N; i++) exist_negative_cycle |= dp[i][i] < 0;

   if (exist_negative_cycle) {
      cout << "NEGATIVE CYCLE" << endl;
   } else {
      for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
         if (dp[i][j] > INF/2) {
            cout << "INF";
         } else {
            cout << dp[i][j];
         }
         if (j == N-1) {
            cout << endl;
         } else {
            cout << " ";
         }
      }
      }
   }
}


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18

const int N = 100 + 1;
int g[N][N], n, m;

bool FloydWarshall(){
   for(int k = 0; k < n; k++){
	   for(int i = 0; i < n; i++){
		  for(int j = 0; j < n; j++){
			  if (g[i][k] == INF || g[k][j] == INF) continue;
			  g[i][j] = min(g[i][j], g[i][k] + g[k][j]);   
		   }  
		}  
	 } 
   for(int i = 0; i < n; i++){
	    if (g[i][i] < 0 ) return false; 
	  }  // check for negative weight cycle	
   return true;
}

int32_t main(){
   	cin >> n >> m;
   	for(int i = 0; i < n; i++){
	  for(int j = 0; j < n; j++){
		   if (i == j) g[i][j] = 0;
		   else g[i][j] = INF;  
		}	
    }
    for(int i = 0; i < m; i++){
	  int x, y , val;
	  cin >> x >> y >> val;
	  g[x][y] = val;	
	}
   bool ok = FloydWarshall();
   if (ok){
	   for(int i = 0; i < n; i++){
		 for(int j = 0; j < n; j++){
			 if (j) cout << " ";
			 if (g[i][j] == INF) cout << "INF";
			 else cout << g[i][j]; 
		   }
		  cout << endl;  
		 }
	 }
   else cout << "NEGATIVE CYCLE" << endl;
}


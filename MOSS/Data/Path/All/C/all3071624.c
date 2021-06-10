#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static const int MAX = 100;

static const long long INF = (1LL << 32 );


int n;
long long d[MAX][MAX];

void floyd() {
  for( int k = 0; k < n; k++ ) {
    for(int i = 0; i < n; i++ ) {
      if( d[i][k] == INF ) continue;
      for( int j = 0; j < n; j++ ) {
        if( d[k][j] == INF ) continue;
        d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
      }
    }
  }
}

int main() {
      
   int s, t, c, e;
  
   cin >> n >> e;
   for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++) {
      d[i][j] = ( (i == j)? 0 : INF );
    }
   }

   while ( e-- ) {
   	  cin >> s >> t >> c;
   	  d[s][t] = c;
   	}
   
    floyd();

    bool negative = false;
    for (int i = 0; i < n; i++ ) if(d[i][i] < 0 ) negative = true;
   
    if( negative ) { cout << "NEGATIVE CYCLE" << endl; }
    else {
      for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ){
          if( j ) cout << " ";
          if (d[i][j] == INF )cout << "INF";
          else cout << d[i][j];
        }
        cout << endl;
      }
    }

   return 0;
}



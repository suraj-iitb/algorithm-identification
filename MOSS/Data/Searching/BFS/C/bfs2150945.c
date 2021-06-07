#include<stdio.h>

int main()
{
  int n, h, i, j, k, l, m, Q[100], Z[100];
  int G[100][100];
  scanf("%d", &n);
  
  for(i = 0; i < 101; i++ ) {
    Z[i] = -1;
    Q[i] = 0;
  }
  
  for( i = 0; i < n; i++){
    scanf("%d", &G[i][0]);
    scanf("%d", &G[i][1]);
    for( j = 2; j < 2 + G[i][1]; j++){
      scanf("%d", &G[i][j]);
    }
  }
  
  m = 0; 
  h = 0; 
  Q[h] = 1;
  Z[1] = 0;
  for( i = 0; i < n; i++){
    k = Q[m];
    l = G[k - 1][1];
    
    for( j = 0; j < l; j++){
      if( Z[ G[k - 1][2 + j] ] == -1 ){
        h++;
        Q[h] = G[k - 1][2 + j];
        Z[ G[k - 1][2 + j] ] = Z[ Q[m] ] + 1;
      }
    }
    m++;
    if( Q[m] == 0 ) i = i + n;
  }
  
  for(i = 1; i <= n ; i++){
    printf("%d %d\n", i, Z[i] );
  }
  
  return 0;
}

#include<stdio.h>



/* プロトタイプ宣言 */
void aaa(int u);
void bbb();

int n, M[1020][1020], fx[1020], d[1020], rx[1020], px;

int main(){
  int  i, j, u, k, v; 

  scanf("%d", &n);

  for ( i = 0; i <n; i++ ){
    for ( j = 0; j <n; j++ ) M[i][j] = 0;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &u, &k);
    u--;
    for ( j = 0; j < k; j++ ){
      scanf("%d", &v);
      v--;
      M[u][v] = 1;
    }
  }
  
  bbb();

  return 0;
}

void bbb() {
  int i, u;
  for ( i = 0; i < n; i++ ) fx[i] = 0;
  px = 0;
  for ( u = 0; u < n; u++ ){
    if ( fx[u] == 0 ) aaa(u);
  }
  for ( i = 0; i < n; i++ ){
    printf("%d %d %d\n", i+1, d[i], rx[i]);
  }
}

void aaa(int u){
  int v;
  fx[u] = 1;
  px++;
  d[u] = px;
  for ( v = 0; v < n; v++ ){
  	if ( M[u][v] == 0 ) continue;
    if ( fx[v] == 0 ) aaa(v);
    
  }
  fx[u] = 2;
  rx[u] = ++px;
}






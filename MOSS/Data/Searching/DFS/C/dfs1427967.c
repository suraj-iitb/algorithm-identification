#include <stdio.h>
#include <stdlib.h>

#define WHITE 0   //未発見
#define GRAY 1    //発見
#define BLACK 2   //終了

char a[100][100]; //隣接行列
int n;            //行列のサイズ
int d[100];       //発見時刻
int f[100];       //終了時刻
int color[100];   //探索状況
int time;         //現在時刻



void init() {
  short i, j;

  for( i=0; i<n; i++ ) {
    for( j=0; j<n; j++ ) {
      a[i][j] = 0;
    }
  }

  return;
}


void visit( short u ) {
  short v;

  color[u] = GRAY;     //uを発見状態に
  d[u] = ++time;       //発見時刻をセット
  
  for( v=0; v<n; v++ ) {
    if( a[u][v] == 1 && color[v] == WHITE ) { //頂点vが現在地uからつながっていて未発見なら
      visit( v );                             //vを訪問する
    }
  }

  color[u] = BLACK;
  f[u] = ++time;

  return;

}


void dfs() {
  short i;
  
  for( i=0; i<n; i++ ) {
    if( color[i] == WHITE ) {
      visit( i );
    }
  }
  return;
}
  

void print() {
  short i;

  for( i=0; i<n; i++ ) {
    printf("%d %d %d\n", i+1, d[i], f[i] );
  }

  return;
}



main() {

  int i, j;
  int u, k, v;

  scanf( "%d", &n );
  
  init();

  
  for( i=0; i<n; i++ ) {
    scanf( "%d%d", &u, &k );
    
    for( j=0; j<k; j++ ) {
      scanf( "%d", &v );
      a[u-1][v-1] = 1;
    }
    
  }

  dfs();
  
  print();
  
  return 0;

} 
  

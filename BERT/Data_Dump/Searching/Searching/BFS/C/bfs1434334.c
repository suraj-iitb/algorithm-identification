#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

char a[100][100]; //隣接行列
int n;            //行列のサイズ
short d[100];     //頂点1からの距離
char color[100];  //探索状況
short q[100];     //キュー
short h, t;       //キューの先頭と末尾


void init() {
 short i;

 for( i=0; i<n; i++ ) {
     d[i] = -1;
 }

 return;
}

void enqueue( short e ) {

 if( (t+1) % 100 != h ) {
   q[t] = e;
   t = (t + 1) % 100;
 }

 return;
}

short dequeue() {
  short r = -1;

 if( h != t ) {
   r = q[h];
   h = (h + 1) % 100;
 }

 return r;
}


void bfs() {
 short i, u;

 //探査状況と最短距離を初期化
 for( i=1; i<n; i++) {
   color[u] = WHITE;
   d[u] = -1;
 }

 color[0] = GRAY;
 d[0] = 0;

 enqueue( 0 );

 while( ( u = dequeue() ) != -1 ) { //キューが空でない
   for( i=0; i<n; i++ ) {

       if( a[u][i] == 1 && color[ i ] == WHITE ) {
	 color[ i ] = GRAY;
	 d[i] = d[u] + 1;
	 enqueue( i );
       }

   }
   color[u] = BLACK;
 }
 
 return;
}


void printDist() {
  short i;
  
  for( i=0; i<n; i++ ) {
    printf( "%d %d\n", i+1, d[i] );
  }
  return;
}


int main() {
  
  short i, j;
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
  
  bfs();
  
  printDist();
  
  return 0;
  
}

#include <stdio.h>

void DFS();
void ReVisit(int);
void print();

int Adj[100][100];
int d[100];
int f[100];
int n, i, j, count;

int main() {
  int u, v, k;

  scanf("%d",&n);

  for( i=0 ; i<n ; i++ ) {
    d[i] = 0;
    f[i] = 0;
    for( j=0 ; j<n ; j++ ) Adj[i][j] = 0;
  }
  
  for( i=0 ; i<n ; i++ ) {
    scanf("%d%d",&u,&k);
    for( j=0 ; j<k ; j++ ) {
      scanf("%d",&v);
      Adj[i][v-1] = 1;
    }
  }

  DFS();
  print();

  return 0;
}

void DFS() {
  count = 1;
 
  for( i=0 ; i<n ; i++ ) {
      if(d[i] == 0)
    ReVisit(i);
    }
}
 
void ReVisit(int u) {
  int l;
  d[u] = count++;
  for( l=0 ; l<n ; l++ ) {
    if(Adj[u][l] == 1 && d[l] == 0) ReVisit(l);
  }
  f[u] = count++;
}

void print() {
  for( i=0 ; i<n ;i++ )
    printf("%d %d %d\n",i+1,d[i],f[i]);
}

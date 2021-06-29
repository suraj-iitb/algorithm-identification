#include<stdio.h>
#include<stdlib.h>

#define null -1
#define WHITE 0
#define GRAY 1  
#define BLACK 2

void DFS(void);
void visit(int);
int next(int);

void Spush(int);
void Spop();

int S[101]; //????????????
int S_i;    //??????????????¨?????°
  
int n;      //????????°
int V[101][101] = {};
int d[101]; //timestanp ??????
int f[101]; //timestanp ??????
int color[101] = {}; 
int t = 0;

int main(){
  int i, j, k, u, m;
  
  scanf("%d",&n);

  for( i=0 ; i<n ; i++ ){
    scanf("%d",&u);

    scanf("%d",&m);
    for( j=0 ; j<m ; j++ ){
      scanf("%d",&k);
      V[u][k] = 1;
    }
  }

  DFS();

  for( i=0 ; i<n ; i++ ){
    printf("%d ",i+1);
    printf("%d %d\n", d[i+1], f[i+1]);
  }
  
  return 0;
}

void DFS(){
  int i;
  
  for( i=0 ; i<n ; i++ ){
    if( color[i+1] == WHITE ){
      visit(i+1);
    }
  }
}

void visit(int r){
  int u;
  int v;
  
  Spush(r);
  color[r] = GRAY;
  d[r] = ++t;

  while( S_i != 0 ){
    u = S[S_i-1];
    v = next(u);

    if( v != null ){
      if( color[v] == WHITE ){
	Spush(v);
	color[v] = GRAY;
	d[v] = ++t;
      }
    }
    else{
      Spop();
      color[u] = BLACK;
      f[u] = ++t;
    }
  }
}

void Spush(int x){
  S[S_i] = x;
  S_i++;
}

void Spop(){
  S[S_i] = 0;
  S_i--;
}

int next(int x){
  int i;

  for( i=0 ; i<n ; i++ ){
    if( V[x][i+1] == 1 && color[i+1] == WHITE ) return i+1;
  }
  return null;
}

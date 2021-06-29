#include<stdio.h>


int a[100][100];
int b[100];
int time,n;
int d[100];
int c[100];


void Root(int u){
  int i;
  c[u] = 1;
  d[u] = ++time;
  for(i = 0; i < n; i++){
    if(!a[u][i]){
        continue;
    }
    if(!c[i]){
        Root(i);
    }
  }
  c[u] = 2;
  b[u] = ++time;
}


void DFS(){
  int e;
  for(e = 0; e < n; e++){
    c[e] = 0;
  }
  time = 0;
  for(e = 0; e < n; e++){

    if(!c[e]){
        Root(e);
    }
  }
  for(e = 0; e < n; e++){
    printf("%d %d %d\n",e + 1,d[e],b[e]);
  }
}

int main(){
  int i, j, u, v, k;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      a[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&v);
    for(j = 0; j < v; j++){
      scanf("%d",&k);
      a[u - 1][k - 1] = 1;
    }
  }

  DFS();


  return 0;
}



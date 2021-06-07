#include <stdio.h>

#define White 2
#define Gray 3
#define Black 4

int d[103],f[103];
int n,time,r;
int A[103][103];
int color[103];

typedef struct Input{
  int u;
  int k;
  int v[1000];
}input;

void DFSvisit(int u){
  int i,j,v;
  
  color[u] = Gray;
  time++;

  d[u] = time;
  //printf("d[%d]=%d\n",u,d[u]);

  for(v = 1 ; v <= n ; v++){
    if(A[u][v] == 1 && color[v] == White){
      DFSvisit(v);  
    }
  }
  
  color[u] = Black;
  time++;

  f[u] = time;
  //printf("f[%d]=%d\n",u,f[u]);
}

int main(void){
  int i,j;
  input Adj[103];
  
  time = 0;

  scanf("%d",&n);

  for(i = 1 ; i <= n ; i++){
    scanf("%d",&Adj[i].u);
    scanf("%d",&Adj[i].k);

    if(Adj[i].k != 0){
      for(j = 1 ; j <= Adj[i].k ; j++){
	scanf("%d",&Adj[i].v[j]);
      }
    }
    
  }

  for(i = 1 ; i <= n ; i++){
    for(j = 1 ; j <= n ; j++){
      A[i][j] = 0;
    }
  }

  for(i = 1 ; i <= n ; i++){
    for(j = 1 ; j <= Adj[i].k ; j++){
      A[Adj[i].u][Adj[i].v[j]] = 1;
    } 
  }
  

  for(i = 1 ; i <= n ; i++){
    color[Adj[i].u] = White;
  }

  for(i = 1 ; i <= n ; i++){
    for(j = 1 ; j <= n ; j++){
      if(A[i][j] == 1){
	if(color[j] == White)
	  DFSvisit(Adj[i].u);
      }
    }
  }
  
  for(i = 1 ; i <= n ; i++){
    printf("%d",Adj[i].u);
    printf(" %d %d\n",d[i],f[i]);
  }
  
  return 0;
}

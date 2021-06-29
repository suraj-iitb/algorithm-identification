#include<stdio.h>

#define g -3
#define w -2
#define b -1


int temp[101];
int time;
int d[101];
int f[101];
int N;
int A[101][101];



void DFS();

void DFSvisit(int u){
  int v;

  temp[u]=g;
  time++;
  d[u]=time;

  for(v=1;v<=N;v++){
    if(A[u][v]==0){
      continue;
    }
    if( temp[v]==w ){
      DFSvisit(v);
    }
  }  
  

  temp[u] = b;
  f[u] = ++time;

}


void DFS(){
  int i;
  for(i=1;i<=N;i++){
    temp[i] = w;
  }
  time=0;

  for(i=1;i<=N;i++){
    if(temp[i]==w){
      DFSvisit(i);
    }
  }
}




main (){

  int i,j,k,v,u;

  for(i=1;i<101;i++){
    for(j=1;j<101;j++){
      A[i][j] = 0;
    }
  }

  scanf("%d",&N);

  for(i=1;i<=N;i++){ 
    scanf("%d %d",&v,&k); 
    for(j=1;j<=k;j++){
      scanf("%d",&u);
      A[v][u] = 1;
    }
  }

  DFS();
   for(i=1;i<=N;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  return 0;
}
 

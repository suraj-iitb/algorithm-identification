#include<stdio.h>

int C[101][101]={0};
int d[101]={0};
int f[101]={0};
int count = 0;
int n;

void DFS(int i){
  int j;
 
  d[i] = ++count;

  for(j=0; j<n; j++){
    if(C[i][j] != 0 && d[j] == 0)
      DFS(j);
  }

  f[i] = ++count;
}

int main(){

  int i,j,k,v,u;
  int id[101];
  
    scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d %d",&id[i],&k);

    for(j=0; j<k; j++){
      scanf("%d",&v);
      C[id[i]-1][v-1]=1;
    }
  }

  for(i=0; i<n; i++){
    if(d[i] == 0)
      DFS(i);
  }

  for(i=0; i<n; i++){
    printf("%d %d %d\n",id[i],d[i],f[i]);
  }

  return 0;
}
  


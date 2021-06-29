#include<stdio.h>
 
#define MAX 1000
#define N 100
 
int G[MAX][MAX];
int d[MAX],Q[N];
int n;
int max=0;
int min=0;
 
void en(int q){
  Q[max] = q;
  max++;
}
 
int de(){
  min++;
  return Q[min-1];
}
 
int size(){
  return max-min;
}
 
void bfs(int i){
  int a;
  for(a = 0; a < n; a++){
    if(G[i][a] == 1 && d[a] == -1){
      d[a] = d[i]+1;
      en(a);
    }
  }
}
 
int main(){
  int i,j,u,k,c;
 
  scanf("%d",&n);
 
  for(i=0;i<MAX;i++){
    d[i]=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      G[u-1][c-1]=1;
    }
  }
  d[0]=0;
  bfs(0);
 
  while(size()!=0){
    bfs(de());
  }
 
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    printf("%d\n",d[i]);
  }
 
  return 0;
}

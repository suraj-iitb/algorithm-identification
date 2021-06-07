#include<stdio.h>
int n;
int A[101][101];
typedef struct{
  int d;
  int f;
}node;
node P[101];
int c=0;
void dfs(int s){
  int i;
  for(i=0;i<n;i++){
    if(A[s][i+1]==1){
      //printf("a%d %d\n",s,i+1);
      if(P[i+1].d == 0){
	//printf("b%d %d\n",i+1,c);
	P[i+1].d = ++c;
	dfs(i+1);
      }
      else continue;
    }
  }
  if(P[s].f==0) P[s].f = ++c;
  return ;
}
int main(){
  int i,j;
  int u,k,v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u][v]=1;
    }
  }
  for(i=0;i<n;i++){
    if(P[i+1].d == 0){
      P[i+1].d = ++c;
      dfs(i+1);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,P[i+1].d,P[i+1].f);
  }
  return 0;
}


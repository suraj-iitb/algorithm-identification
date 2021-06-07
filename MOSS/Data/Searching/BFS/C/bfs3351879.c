#include<stdio.h>
void bfs(int ,int);
void bbfs(int,int);
int A[101][101];
int Ans[101];
int n;
int main(){
  int i,j,num,d,x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&num,&d);
    for(j=0;j<d;j++){
      scanf("%d",&x);
      A[num][x]=1;
    }

  }
  for(i=1;i<=n;i++){

      Ans[i]=-1;
    

  }
  bfs(1,0);
 
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,Ans[i]);
  }
  return 0;
}
void bfs(int u,int num){
  int i;
  Ans[u]=num;
  for(i=1;i<=n;i++){
    if(A[u][i]==1){
      if(Ans[i]==-1||Ans[i]>num+1)
      bfs(i,num+1);
    }
  }

}


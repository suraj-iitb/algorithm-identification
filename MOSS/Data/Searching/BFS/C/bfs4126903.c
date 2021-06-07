#include <stdio.h>
#include <stdlib.h>
#define N 100

void visit(int);
int n,arr[N+1][N+1],count[N+1],cnt=0;
int main(){
  int i,j,m,node,num;
  
  scanf("%d",&n);
  if(n<1 || n>100) exit(2);
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      arr[i][j]=0;
    }
  }
  count[0]=999;
  for(i=0;i<n;i++){
    count[i+1]=999;
    scanf("%d %d",&node,&num);
    for(j=0;j<num;j++){
      scanf("%d",&m);
      arr[node][m]=1;
    }
  }
  visit(1);

  for(i=1;i<=n;i++){
    if(count[i] == 999){ // 1の頂点とつながっていないとき
      printf("%d %d\n",i,-1);
    }else{
      printf("%d %d\n",i,count[i]);
    }
  }
  
  return 0;
}

void visit(int x){
  int i;
  count[x]=cnt;
  for(i=1;i<=n;i++){
    if(arr[x][i]==1 && count[i]>cnt){
      cnt++;
      visit(i);
      cnt--;
    }
  }
}


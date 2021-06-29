#include <stdio.h>
#include <stdlib.h>
#define N 100

void DFS(int);

int count=1,d[N+1],f[N+1],arr[N+1][N+1],
n;

int main(){
  int i,j,m,node,num;

  scanf("%d",&n);
  if(n<1 || n>N) exit(2);
    f[0]=d[0]=0;
  for(i=0;i<n;i++){
    f[i+1]=d[i+1]=0;
    scanf("%d %d",&node,&num);
    for(j=0;j<num;j++){
      scanf("%d",&m);
      arr[node][m]=1;
    }
  }

  DBF(1);
  for(i=1;i<=n;i++){
    if(d[i] == 0){
      count++;
      DBF(i);
    }
    printf("%d %d %d\n",i,d[i],f[i]);
  }
   
  return 0;
}

void DBF(int x){
  int i,j;
  
  d[x]=count;
  for(i=1;i<=n;i++){
    if(arr[x][i]==1 && d[i] == 0){
      count++;
      DBF(i);
    }
  }
  
  count++;
  f[x]=count;
}


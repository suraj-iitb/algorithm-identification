#include <stdio.h>

#define MAX 100

int M[MAX][MAX];
int disc[MAX];
int t;
int finish[MAX];

void df(int id, int n){
  int i;
  
  if (finish[id]!=0){
    return;
  }
  else if(disc[id]==0){
    disc[id]=(++t);
  }

  for(i=0;i<n;i++){
    if(M[id][i]==1 && disc[i]==0){
      disc[i] = (++t);
      df(i, n);
    }
  }
  finish[id]=(++t);
}

int main(){
  int i,j,n,a,k,b;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
    disc[i]=0;
    finish[i]=0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&a,&k);
    for(j=0;j<k;j++){
      scanf("%d",&b);
      M[a-1][b-1]=1;
    }
  }

  t=0;
  for(i=0;i<n;i++){
    df(i,n);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,disc[i],finish[i]);
  }
  return 0;
}


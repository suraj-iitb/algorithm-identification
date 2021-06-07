#include <stdio.h>
#define MAX 100

void DepthFirstSearch();
void roop(int );

int d[MAX],f[MAX],arr2[MAX];
int N,time;
#define MAX 100
#define IN -1
int a[MAX][MAX];

int main(){
  int i,j,count,num,arr;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      a[i][j]=0;
    }
    d[i]=0;
    f[i]=0;
    arr2[i]=0;
  }
  for(i=0;i<N;i++){
    scanf("%d%d",&num,&count);
    for(j=0;j<count;j++){
      scanf("%d",&arr);
      a[num-1][arr-1] = 1;
    }
  }
  DepthFirstSearch();
  for(i=0;i<N;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void DepthFirstSearch(){
  int i;
  time = 0;

  for(i=0;i<N;i++){
    if(arr2[i]==0){
      roop(i);
    }
  }
}

void roop(int i){
  int j;

  arr2[i]=IN;
  d[i] = ++time;
  for(j=0;j<N;j++){
    if(a[i][j] == 0) continue;
    if(arr2[j]==0){
      roop(j);
    }

  }
  arr2[i]=1;
  f[i] = ++time;
}

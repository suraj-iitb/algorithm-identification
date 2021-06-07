#include<stdio.h>
#define N 101
int total,time,A[N][N],B[N],C[N],D[N];
void depth(int a){
  int i; C [a]=1,D[a]=++time;
  for(i=0;i<total;++i){
    if(A[a][i]==1){
      if(C[i]==0)depth(i);
    }
  }
  C[a]=2;
  B[a]=++time;
}
int main(){
  int i,j,a,b,c;
  scanf("%d",&total);
  for(i=0;i<total;++i){
    C[i]=0;
    for(j=0;j<total;j++){
      A[i][j]=0;
    }
  }
  time=0;
  for(i=0;i<total;++i){
    scanf("%d%d",&a,&b);
    for(j=0;j<b;j++){
      scanf("%d",&c);
      A[a-1][c-1]=1;
    }
  }
  for(i=0;i<total;++i){
    if(C[i]==0)depth(i);
  }
  for(i=0;i<total;++i){
    printf("%d %d %d\n",i+1,D[i],B[i]);
  }
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define VMAX 10000

int main(){
  unsigned short *A,*B; /*これじゃないとダメらしい*/
  int C[VMAX];
  int i,j,n;

  scanf("%d",&n);
  A=malloc(sizeof(short)*n);
  B=malloc(sizeof(short)*n);
  for(i=1;i<=n;i++)scanf("%d",&A[i]);

  for(i=0;i<=VMAX;i++)C[i]=0;
  for(j=1;j<=n;j++)C[A[j]]++;
  for(i=1;i<=VMAX;i++)C[i]=C[i]+C[i-1];
  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i!=n)printf("%d ",B[i]);
    else printf("%d\n",B[i]);
  }

  return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define VMAX 10000

int A[MAX],B[MAX];

int main(){
  int n,i,j;
  int C[VMAX+1];

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>VMAX){
      exit(1);
    }
  }

  for(i=0;i<VMAX+1;i++){
    C[i]=0;
  }

  //C[i]にiの出現数を記録する
  for(i=1;i<=n;i++){
    C[A[i]]++;
  }

  //C[i]にi以下の数の出現数を記録する
  for(i=1;i<VMAX+1;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  return 0;
}

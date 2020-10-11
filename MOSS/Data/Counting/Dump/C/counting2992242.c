#include<stdio.h>
#define MAX 2000001
#define VMAX 10000
int main()
{
  int i,n;
  scanf("%d",&n);
  int A[n+1],B[n+1];
  int j,C[VMAX+1];
  int k=VMAX;
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n)printf(" ");
  }
  printf("\n");
  return 0;
}



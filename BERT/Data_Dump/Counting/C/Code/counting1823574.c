#include<stdio.h>
#define N 2000000

int A[N],B[N],C[N]={ };

int main(){

  int i,j,n;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=N;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
    else printf("\n");
  }
  return 0;
}

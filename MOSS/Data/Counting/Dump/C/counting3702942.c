#include <stdio.h>

int n,A[2000001],B[2000001],C[10001];
void countingsort(int k){
  int i,j;
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
int main(){
  int k=0,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k<A[i]) k=A[i];
    B[i]=0;
  }
  countingsort(k);
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n) printf(" ");
  }
  printf("\n");
  return 0;
}


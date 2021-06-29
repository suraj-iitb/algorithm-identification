#include<stdio.h>
void CS(long *,long *,long *,long,long);
#define N 2100000
int main(){
  long A[N],B[N],C[N];
  long i,k=0,j,n;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k<A[i]){
      k=A[i];
    }
  }
  CS(A,B,C,k,n);
  return 0;
}


void CS(long *A,long *B,long *C,long k,long n){
  long i,j;
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
  for(i=1;i<=n; i++){
    printf("%d",B[i]);
    if(i != n) printf(" ");
  }
  printf("\n");

}


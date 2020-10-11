#include<stdio.h>

#define K 10000

int A[20000001];
int B[20000001];
int C[K];

int main(){
  int i,j;
  int n;

  scanf("%d",&n);

  for(i=0;i<K;i++) C[i]=0;

  for(j=1;j<=n;j++){
    scanf("%d",&A[j]);
    C[A[j]]++;
  }

  for(i=1;i<=K;i++) C[i]=C[i]+C[i-1];
  
  for(j=n;1<=j;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i!=1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
    return 0;
}

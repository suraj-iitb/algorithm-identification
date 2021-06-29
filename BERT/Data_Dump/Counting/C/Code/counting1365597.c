#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int n;
void CountingSort(int *A,int *B){
  int i,j;
  int C[MAX+1];
  for(i=0;i<=MAX;i++) C[i]=0;
  for(j=0;j<n;j++) C[A[j]]++;
  for(i=1;i<=MAX;i++) C[i]=C[i]+C[i-1];
  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
int main(void){
  int *A;
  int *B;
  int i;
  scanf("%d",&n);
  A=malloc((n+1)*sizeof(int));
  B=malloc((n+1)*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  CountingSort(A,B);
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
  return 0;
}

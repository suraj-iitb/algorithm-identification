#include<stdio.h>
#define N 2000001
int B[N], C[N];

void countingSort(int A[], int B[], int k, int num){
  int i, j;

  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=num;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=num;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=num;i++){
    printf("%d", B[i]);
    if(i!=num) printf(" ");
  }
  printf("\n");
}

int main(){
  int A[N];
  int i,j,n,k=0;
  scanf("%d", &n);
  for(i=1;i<=n;i++){
    scanf("%d", &A[i]);
    if(k < A[i]) k=A[i];
  }
  countingSort(A, B, k, n);
  return 0;
}


#include<stdio.h>
#define N 2000001
int A[N],B[N],n;

void CountingSort(int k){
  int C[k+1],i,j;
  for (i=0; i<k; i++){
    C[i]=0;
  }

  for (j=1;j<=n;j++){
    C[A[j]]++;
  }

  for (i=1;i<k;i++){
    C[i] += C[i-1];
  }

  for (j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}


int main(){
  int i,key=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if (key<A[i]){
      key=A[i];
    }
  }
  CountingSort(key+1);

  for (i=1;i<=n;i++){
    if (i!=1){
      printf(" ");
    }
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

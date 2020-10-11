#include<stdio.h>

int A[2000001],B[2000001],n;

void CountingSort() {
  int i,j,k=10000;
  int C[k];

  for(i=0;i<k;i++){
    C[i] = 0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    //printf("%d\n",C[A[j]]);
    C[A[j]]--;
      }
}

int main() {
  int i;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  CountingSort();

  for(i=1;i<=n;i++){
    if(i==1) printf("%d",B[i]);
    else printf(" %d",B[i]);
  }

  printf("\n");

  return 0;
}
  
  


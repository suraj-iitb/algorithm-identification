#include <stdio.h>
int n;

void CountingSort(int *,int *,int );
int main(){

  int i,j;
  int C[2000000];
  int newC[2000000];
  scanf("%d",&n);
  for(i = 0;i <n ; i++){
    scanf("%d",&C[i]);
  }
  
  CountingSort(C,newC,n);
  return 0;
}

void CountingSort(int *A,int *B,int k){
  int i,j;
  int C[1000000];
  for(i=0;i<=100000;i++){
    C[i] = 0;
  }
  
  for(j = 1; j<=n;j++){
    C[A[j-1]]++;
  }
  
  for(i = 1; i<=1000000; i++){
    C[i] = C[i] + C[i-1];
  }
  /*
  printf("A[i]: ");
  for(i=0;i<n;i++){
    printf("%2d ",A[i]);
  }

  
  printf("\n");
 printf("C[i]: ");
  for(i=0;i<n;i++){
    printf("%2d ",C[i]);
  }
    printf("\n");
 printf("A[j-1]: ");
  for(j = n; j>=1; j--){
    printf("%2d ",A[j-1]);
  }
    printf("\n");
     printf("C[A[j-1]]: ");
  for(j = n; j>=1; j--){
    printf("%2d ",C[A[j-1]]);
  }
  printf("\n");
  */
  for(j = n; j>=1; j--){
    B[C[A[j-1]]] = A[j-1];
    C[A[j-1]]--;
  }
  
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d",B[i]);
  printf("\n");
}


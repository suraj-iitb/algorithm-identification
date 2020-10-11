#include<stdio.h>
#define MAX 2000001
int CountingSort(int);
int A[MAX],B[MAX],C[10001],k;

main(){

  int n;
  int i;

  k=0;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
    if(A[i]>k)
      k=A[i];
  }

  CountingSort(n);

  for(i=1;i<=n;i++){
    printf("%d", B[i]);
    if(i!=n)
      printf(" ");
  }
  printf("\n");

  return 0;

}

int CountingSort(int n){

  int i,j;
  
  for(i=0; i<=k; i++)
    C[i]=0;
  for(j=0; j<n; j++)
    C[A[j]]=C[A[j]]+1;
  for(i=1; i<=k; i++)
    C[i]=C[i]+C[i-1];
  for(j=n-1; j>=0; j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
}

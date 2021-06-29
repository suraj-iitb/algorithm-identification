#include <stdio.h>
#include <stdlib.h>

void CountingSort(int *,int *,int,int);

int main()
{
  int n,*A,*B,i,max=0;
  
  scanf("%d",&n);

  A = (int *)malloc((n+1) *sizeof(int));
  B = (int *)malloc((n+1) *sizeof(int));

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(max<A[i]) max = A[i];
  }

  CountingSort(A,B,max,n);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n) printf(" ");
    else printf("\n");
  }

  free(A);
  free(B);

  return 0;
}

void CountingSort(int *A,int *B,int k,int n)
{
  int *C,i,j;

  C = (int *)malloc((k+1) * sizeof(int));
  
  for(i=0;i<=k;i++){
    C[i] = 0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i] = C[i]+C[i-1];
  }

  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  free(C);
}

    
    
  
  


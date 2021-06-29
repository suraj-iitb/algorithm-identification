#include<stdio.h>
#define E 2000000

void CountingSort(int A[], int B[], int n)
{
     int i,j,C[E];
     for(i = 0; i<E; i++) C[i] = 0;

     /* C[i] に i の出現数を記録する */
     for(j = 0; j<n; j++) C[A[j]]++;

     /* C[i] に i 以下の数の出現数を記録する*/
     for(i = 1; i<=E; i++) C[i] = C[i] + C[i-1];

     for(j = n-1; j>=0; j--)
     {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
     }
}


int main()
{
  int i,n,A[E],B[E];
  scanf("%d",&n);

  for(i=0; i<n; i++) scanf("%d",&A[i]);
  for(i=0; i<n; i++) B[i]=0;

  CountingSort(A, B, n);

  for(i=1; i<=n; i++)
  {
    printf("%d",B[i]);
    if(i<n) printf(" ");
  }

  printf("\n");

  return 0;
}

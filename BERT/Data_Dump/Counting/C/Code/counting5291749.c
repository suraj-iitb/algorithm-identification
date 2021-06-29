#include<stdio.h>
#define L 2000001

int A[L];
int B[L]; 
int C[L];

int main()
{
  int i,j,N;
  scanf("%d",&N);
  for(i = 0; i < N; i++){
      scanf("%d",&A[i]);
  }
  for(i = 0; i < L; i++){
      C[i] = 0;
  }
  for(i = 0; i < N; i++){
      C[A[i]]++;
   }
  for(i = 1; i < L; i++){
      C[i] += C[i-1];
  }
  for(i = N-1; i >= 0; i--)
    {
      B[C[A[i]]] = A[i];
      C[A[i]]--;
    }
  for(i = 1; i < N+1; i++)
    {
      printf("%d",B[i]);
      if(i == N)printf("\n");
      else printf(" ");
    }
  return 0;
}

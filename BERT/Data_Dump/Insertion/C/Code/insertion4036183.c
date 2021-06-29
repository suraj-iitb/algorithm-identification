#include <stdio.h>
void X(int S[],int N){
  int i;
  for (i=0;i<N;i++){
    if (i>0)
      printf (" ");
    printf ("%d",S[i]);
  }
  printf ("\n");
}
void Y(int A[], int N) {
  int i,j,v;
  for (i=1;i<N;i++){
    v = A[i];
    j = i - 1;
    while (j >= 0 &&A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    X(A,N);
  }
}

int main()
{
  int A,i;
  int hi[100];

  scanf ("%d",&A);
  for (i=0;i<A;i++)
    scanf("%d",&hi[i]);
  X(hi,A);
  Y(hi,A);

  return 0;
}
  


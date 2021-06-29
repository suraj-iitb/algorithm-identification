#include <stdio.h>

void swap(int* A, int N, int j);
int c=0;

int main()
{
  int N,i,j,A[100];

  scanf("%d",&N);
  for(i = 0; i < N; i++) scanf("%d",&A[i]);

  for(j = 1; j < N; j++) swap(&A[0], N, j);

  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n",c);

  return 0;
}

void swap(int* A, int N, int j)
{
  int i,temp,min=1000;

  for(i = j; i < N; i++){
    if(min > A[i]){
      min = A[i];
      temp = i;
    }
  }
  
  if(A[j-1] > min){
    A[temp] = A[j-1];
    A[j-1] = min;
    c++;
  }
}
  


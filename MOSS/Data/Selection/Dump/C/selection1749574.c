#include <stdio.h>

int main()
{
  int N, A[100], i, j;
  int  c=0, minj, x;

  scanf("%d",&N);
  for(i = 0 ; i < N ; i++)
    scanf("%d",&A[i]);

  for(i = 0 ; i < N ; i++){
    minj = i;
    for(j = i ; j < N ; j++){
      if(A[j] < A[minj])
	minj = j;
    }
    x = A[i];
    A[i] = A[minj];
    A[minj] = x;
    if(minj != i)
      c++; 
    }
  i=0;
  while(1){
    printf("%d",A[i]); 
    if(i == N-1)break;
    printf(" ");
    i++;
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}

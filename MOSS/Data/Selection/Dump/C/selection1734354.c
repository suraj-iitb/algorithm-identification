#include<stdio.h>
#define N 100

int main()
{
  int i,j,n,k=0,minj,min,temp;
  int A[N];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

  i = 0;
  for(i = 0 ; i < n ; i++){
    minj = i;

    for(j = i ; j <= n-1 ; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(A[i] != A[minj]) {
      temp = A[minj];
      A[minj] = A[i];
      A[i] = temp;
      k+=1;
  }
  }

  for(i = 0 ; i < n-1 ; i++)
    printf("%d ",A[i]);

  printf("%d\n%d\n",A[i],k);

  return 0;
}

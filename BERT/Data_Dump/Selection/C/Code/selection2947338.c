#include<stdio.h>
#define N 100

int main()
{
  int i,j,A[N],minj,n,ch,count=0;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] > A[minj]){
      count++;
    }
	ch = A[i];
	A[i] = A[minj];
	A[minj] = ch;
  }

  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}


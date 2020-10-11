#include<stdio.h>

void bubblesort(int *,int);

void bubblesort(int *A,int N)
{
  int a,i,flag=1,count=0;

  while(flag) {
    flag = 0;
    for(i=N-1;i>=1;i--){
    if(A[i] < A[i-1]) {
      a = A[i];
      A[i] = A[i-1];
      A[i-1] = a;
      flag = 1;
      count++;
    }
   }
  }

  for(i=0;i<N;i++) {
      printf("%d",A[i]);
      if(i<N-1)printf(" ");
  }
    
    printf("\n");
    
    printf("%d\n",count);
}

int main()
{
    int N,A[100],i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    scanf("%d",&A[i]);
    
    bubblesort(A,N);

    return 0;
}


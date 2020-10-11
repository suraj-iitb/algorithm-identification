#include<stdio.h>
#define M 100

int main(){
  int i, j, N, flag, A[M], count=0, a;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=N-1;j>i;j--){
      if(A[j-1]>A[j]){
	   a = A[j-1];
	  A[j-1]=A[j];
	  A[j]=a;
	  count++;
      }
      flag=1;
    }
    i++;
  }
  printf("%d",A[0]);
    for(i=1;i<N;i++)
      printf(" %d",A[i]);
    
    printf("\n%d\n",count);

    return 0;
}
  


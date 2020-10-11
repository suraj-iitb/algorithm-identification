#include <stdio.h>

int bubbleSort(int *,int);

int main(){
  int i=0;
  int j=0;
  int count=0;
  scanf("%d",&i);
  int A[i];
  for(j=0;j<i;j++){
    scanf("%d",&A[j]);
  }
  count=bubbleSort(A,i);
  for(j=0;j<i;j++){
    printf("%d",A[j]);
    if(j!=i-1) printf(" ");
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

int bubbleSort(int *A,int N){
  int flag=1;
  int j=0;
  int swapnumber=0;
  int count=0;
  while(flag)
    {
      flag=0;
      for(j=N-1;j>=1;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      swapnumber=A[j];
	      A[j]=A[j-1];
	      A[j-1]=swapnumber;
	      flag =1;
	      count++;
	    }
	}
    }
  return count;
}


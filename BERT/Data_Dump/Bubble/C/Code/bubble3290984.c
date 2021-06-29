#include<stdio.h>
int bubbleSort(int A[],int N);

int main(){

  int i,A[100],N,count;
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++)scanf("%d",&A[i]);
  count = bubbleSort(A,N);
  for(i = 0 ; i < N ; i++){
    if(i > 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

int bubbleSort(int A[], int N){
  int count = 0,flag,j,s;
  flag = 1 ;
  while (flag)
    {
      flag = 0;
      for (j = 1 ; j < N ; j++)
        {
          if (A[j] < A[j-1])
            {
              s = A[j];
              A[j] = A[j-1];
              A[j-1] = s;
              flag = 1;
              count++;
	                  }
        }
    }
  return count;
}



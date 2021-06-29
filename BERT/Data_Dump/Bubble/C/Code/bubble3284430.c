#include <stdio.h>

int bubbleSort(int *,int);

int main()
{
  int A[100],N,i,sw;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  sw = bubbleSort(A,N);
  
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;

}

int bubbleSort(int A[],int N){
  int flag,i,j,sw,a;
  
  sw = 0;
  flag = 1;

  i=0;
  while(flag){
    flag = 0;
    for(j=N-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
      flag = 1;
      sw++;
      }
    }
    i++;
  }
  return sw;
}


#include<stdio.h>
int bubbleSort(int A[],int);
int main()
{
  int N,i,j,cn=0;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  cn = bubbleSort(A,N);
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cn);
  return 0;
}

int bubbleSort(int A[],int N){
    int j,i,r;
    int cnt=0;
    for(j=0;j < N+1;j++){
      for(i=N-1;i > 0;i--){
	if(A[i] < A[i-1]){
	r = A[i];
	A[i] = A[i-1];
	A[i-1] = r;
	cnt++;
      }
    }
  }
    return cnt;
  }
	 
	
      
  


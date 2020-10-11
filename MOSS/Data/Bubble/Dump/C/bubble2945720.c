#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int [],int);

int main(){
  int n,cnt;
  int *A;
  int i;
  
  scanf("%d",&n);

  A = (int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++)
    scanf("%d",&A[i]);

  cnt = bubbleSort(A,n);

  for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n");

  printf("%d\n",cnt);
  
  free(A);
  return 0;
}

int bubbleSort(int A[],int n){
  int flag = 1;
  int tmp, cnt=0;
  int i;
  
  while(flag){
    flag = 0;

    for(i=n-1; i>=1; i--){
      if(A[i] < A[i-1]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	
	cnt++;
	flag = 1;
      }
    }
  }

  return cnt;
}


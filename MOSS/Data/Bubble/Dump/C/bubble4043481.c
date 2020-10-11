#include<stdio.h>

void bubblesort(int[],int);

int main(){
  int A[1000];
  int i,N,count=0;

  scanf("%d",&N);
  if(N <= 0 && N >= 100)return 0;

  for( i = 0 ;i < N ; i++ ){
    scanf("%d",&A[i]);
  }
  bubblesort(A,N);

  
  return 0;
}

void bubblesort(int A[],int N){
  int i,flag=1,j,ex,count=0;
  
  for(i=0;flag;i++){
      flag=0;
      for( j = N-1 ; j >= i+1 ; j-- ){
	if( A[j] < A[j-1] ){
	  ex = A[j];
	  A[j] =  A[j-1];
	  A[j-1] = ex;
	  flag = 1;
	  count++;
	}
      }
    }
    for( i = 0 ; i < N ; i++ ){
      if( i > 0 )printf(" ");
      printf("%d",A[i]);
    }

    printf("\n%d\n",count);
  }


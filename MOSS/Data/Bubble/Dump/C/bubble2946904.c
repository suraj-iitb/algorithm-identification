#include<stdio.h>
int bubbleSort(int[], int);
int main(){
  int N, i, con;
  int A[100];

  scanf("%d",&N);
  for( i = 0 ; i < N ; i++ ){
    scanf("%d",&A[i]);
  }

  con = bubbleSort(A, N);

  printf("%d",A[0]);
  for( i = 1 ; i < N ; i++ ){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",con);
  return 0;
}

int bubbleSort(int A[], int N){
  int j, tmp, con=0;
  int flag=1;
  while( flag ){
    flag = 0;
    for( j = N-1 ; j > 0 ; j-- ){
      if( A[j] < A[j-1] ){
	con++;
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag = 1;
      }
    }
  }
  return con;
}


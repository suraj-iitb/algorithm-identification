#include<stdio.h>

void bubbleSort(int A[],int N){
  int j,i,v,k,flag,cnt=0;
  flag = 1;
  for(i=0; i< N-1 ; i++){
    for(j=N-1 ; j > i;j--){
      if(A[j] < A[j-1]){
	v=A[j - 1];
	A[j-1]=A[j];
	A[j]=v;
	cnt++;
      }
    }
	
  }
   for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k<N-1)printf(" ");
      else printf("\n");
    }
   printf("%d\n",cnt);
}

int main(){
  int N, i;
  int A[100];
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);
  bubbleSort(A,N);
  return 0;
}


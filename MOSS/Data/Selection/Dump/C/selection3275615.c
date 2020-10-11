#include<stdio.h>

void selectionSort(int A[],int N){
  int j,i,v,k,minj=0,cnt=0;
  for(i=0; i< N-1 ; i++){
    minj=i;
    for(j=i ; j < N ;j++){
      if(A[j] < A[minj])minj=j;
    }
	v=A[i];
	A[i]=A[minj];
	A[minj]=v;
	if(i != minj)cnt++;
	
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
  selectionSort(A,N);
  return 0;
}


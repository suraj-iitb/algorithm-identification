#include<stdio.h>

void selectSort(int A[],int N){
  int i,j,minj,temp,num=0;
  for(i = 0; i < N-1; i++){
    minj=i;
    for(j = i+1; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] > A[minj]){
	temp = A[i];
	A[i] = A[minj];
	A[minj] = temp;
	num++;
    }
  }
   for(i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i== N-1)  break;
      printf(" ");
   }
   printf("\n%d\n", num);
}
int main(){
   int i,j,N;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  selectSort(A,N);
  return 0;
}

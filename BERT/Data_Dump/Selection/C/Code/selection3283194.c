#include<stdio.h>
#define N 100

void selectionSort(int[],int);

int main(){
  int n,i;
  int A[N];
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);
  return 0;
}

void selectionSort(int A[],int n){
  int i,j,minj;
  int swap,count = 0;

  for(i = 0; i <= n - 1; i++){
    minj = i;
    for(j = i; j <= n - 1; j++){
      if(A[j] < A[minj]) {
	minj = j;
      }
    }
    if(i != minj) count++;
     swap = A[i];
     A[i] = A[minj];
     A[minj] = swap;
     
  }
  
  for(i = 0; i < n; i++){
     if(i == n - 1) printf("%d",A[i]);
     else printf("%d ",A[i]);
  }
  printf("\n%d\n",count);
}


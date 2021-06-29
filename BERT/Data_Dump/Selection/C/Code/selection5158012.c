#include <stdio.h>

int n,cnt = 0;

void selectionSort(int *);

int main(){
  int i,j,k;
  int A[101];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A);
  
  for(i = 0;i < n;i++){
    printf("%d",A[i]);
    if(i != n-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",cnt);

  return 0;
}

void selectionSort(int *A){
  int i,j,minj,tmp;
  for(i = 0;i < n;i++){
    minj = i;
    for(j = i+1;j < n;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] > A[minj]){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      cnt++;
    }
  }
}


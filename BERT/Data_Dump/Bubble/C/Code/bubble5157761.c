#include <stdio.h>

int n,cnt = 0;

void bubbleSort(int *);

int main(){
  int i,j;
  int A[101];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf(" %d",&A[i]);
  }

  bubbleSort(A);

  for(i = 0;i < n;i++){
    printf("%d",A[i]);
    if(i != n-1)printf(" ");
    else printf("\n");
  }

  printf("%d\n",cnt);

  return 0;
}

void bubbleSort(int *A){
  int i,j,tmp;

  for(i = 0;i < n;i++){
    for(j = n-1;j > i;j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	cnt++;
      }
    }
  }
}


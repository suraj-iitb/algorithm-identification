#include<stdio.h>

void bubbleSort(int);

int main(){
  int n;

  scanf("%d",&n);

  bubbleSort(n);

  return 0;
}

void bubbleSort(int n){
  int A[n], i, j, flag = 1, v, count = 0;

  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);

  while(flag){
    flag = 0;
    for(j = n - 1; j >= 1; j--){
      if(A[j] < A[j - 1]){
	v = A[j];
	A[j] = A[j - 1];
	A[j - 1] = v;
	flag = 1;
	count++;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n - 1)
      printf(" ");
  }
  printf("\n%d\n",count);
}


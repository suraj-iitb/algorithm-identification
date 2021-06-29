#include<stdio.h>

void bubblesort(int A[], int n);
int count;

int main(){
  int n, k;
  int A[100];

  scanf("%d", &n);
  for(k = 0; k < n; k++){
    if(k == n-1){
      scanf("%d", &A[k]);
    }else{
      scanf("%d ", &A[k]);
    }
  }

  count = 0;
  for(k = 0; k < n; k++){
    bubblesort(A, n);
  }

  for(k = 0; k < n; k++){
    if(k == n-1){
      printf("%d\n", A[k]);
    }else{
      printf("%d ", A[k]);
    }
  }

  printf("%d\n", count);

  return 0;
}

void bubblesort(int A[], int n){
  int i, j, flag;
  int tmp;

  flag = 1;
  i = 0;

  while(flag == 1){
    flag = 0;
    for(j = n-1; j >= i+1; j--){
      if(A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        count++;
      }
    }
    i++;
  }
}


#include <stdio.h>
#define N 100

void swap(int,int);
void sort(int *,int);
int main() {
  int i,n;
  int array[N];
  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d",&array[i]);
  }

  sort(array,n);
  return 0;
}

void sort(int *A,int n){
  int i,j,minj=0,cnt=0,temp;
  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i; j <= n-1; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    if(i!=minj){
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    cnt++;
    }
  }
  for (i = 0; i < n; i++) {
    if (i > 0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
}


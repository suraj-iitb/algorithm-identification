#include <stdio.h>
#define N 100

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
  int i,j,k,cnt=0,temp,flag=1;
  i = 0;
  while (flag) {
    flag = 0;
    for (j = n-1; j >= i+1; j--) {
      if (A[j] < A[j-1]) {
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        cnt++;
        flag = 1;
      }
    }
    i++;
  }
  for (i = 0; i < n; i++) {
      if (i > 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
}

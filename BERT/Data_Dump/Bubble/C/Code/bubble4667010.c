#include<stdio.h>
#define N 100
#define MAX 100

int main(){
  int i, j, n, flag, save, count=0;
  int A[MAX];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(A[j] < A[j-1]){
        save = A[j];
        A[j] = A[j-1];
        A[j-1] = save;
        flag = 1;
        count++;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n",count);


  return 0;
}



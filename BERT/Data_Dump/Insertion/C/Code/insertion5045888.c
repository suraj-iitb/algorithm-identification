#include <stdio.h>
#define N 100
int main(){

  int v,i,n,j;
  int A[N];


  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n-1){
      printf(" ");
  }
  }
  printf("\n");

  for(i = 1; i <= n - 1; i++){
    v = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
        A[j+1] = v;
    }
     for(j = 0; j < n; j++){
    printf("%d",A[j]);
    if(j != n-1){
      printf(" ");
    }
  }
  printf("\n");
  }

  return 0;
}




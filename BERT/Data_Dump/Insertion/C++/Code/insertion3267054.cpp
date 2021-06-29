#include<stdio.h>
#define N 1000

int main(){
  int n, i, j, tmp;
  scanf("%d",&n);
  
  int A[n];
  for(i = 0; i < n; i++) scanf("%d", &A[i]);

  for(j = 0; j < n; j++){
    if(j == n-1) printf("%d",A[j]);
    else printf("%d ",A[j]);
  }
  printf("\n");

  for(i = 1; i < n; i++){
    tmp = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > tmp){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = tmp;
    
    for(j = 0; j < n; j++){
      if(j == n-1) printf("%d",A[j]);
      else printf("%d ",A[j]);
    }
    printf("\n");
  }

  return 0;
}


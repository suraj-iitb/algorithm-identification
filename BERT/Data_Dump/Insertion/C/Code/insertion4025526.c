#include <stdio.h>
#define N 100

int main(){
  int i = 0, j = 0, k = 0, n = 0;
  int key = 0;
  int A[N];

  scanf("%d\n",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 1; i <= n; i++){
    
    for(k = 0; k < n; k++){
      printf("%d",A[k]);
      if(k == n-1){
	printf("\n");
      }
      else printf(" ");
    }
    
    key = A[i];
    j = i - 1;
    
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    
    A[j+1] = key;
  }
  
  return 0;
}


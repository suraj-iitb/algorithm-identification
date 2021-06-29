#include <stdio.h>
#include <stdlib.h>

int main(){
  int A[1000];
  int i, v, j, k, n;
  
  scanf("%d", &n);
  
  if(1 > n && n > 100) exit(1);
  for(i = 0; i <= n - 1; i++){
    scanf("%d", &A[i]);
  }
  for(i = 0; i <= n - 1; i++){
    printf("%d", A[i]);
    if(i == n - 1) printf("\n");
    else printf(" "); 
    }
  
  for(i = 1; i <= n - 1; i++){
    v = A[i];
    j =i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k = 0; k <= n - 1; k++){
      printf("%d", A[k]);
      if(k == n - 1) printf("\n");
      else printf(" ");
    }
  }    
  return 0;
}


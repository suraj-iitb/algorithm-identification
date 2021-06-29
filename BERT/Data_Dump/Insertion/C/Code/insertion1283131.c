#include <stdio.h>
#include <stdlib.h>

int main(){
  int *A;
  int i, v, j, k, e, n, count=0;

  while(1){
    scanf("%d",&n);
    if(n >= 0 && n <= 1000){
      break;
    }
  }

  A = (int *)malloc(n*sizeof(int));
  
    for(i = 0; i < n; i++){
      scanf("%d",&e);
      A[i] = e;
      if(i == n-1) printf("%d",A[i]);
      else printf("%d ",A[i]);
    }

    printf("\n");

    for(i=1; i<n; i++){
      v = A[i];
      j= i-1;
      while(j >=0 && A[j] > v){
	A[j+1] = A[j];
	j--;
      }
      A[j+1] = v;
      for(k = 0; k < n; k++){
	if(k == n-1) printf("%d",A[k]);
	else printf("%d ",A[k]);
      }
      printf("\n");
      count++;
      if(count > 100) break;
    }
    return 0;
}

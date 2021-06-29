#include<stdio.h>

int main(){
  int i, j, k, n, tmp, v;
  int A[1000];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  for(k=0; k<n-1; k++){
    printf("%d ", A[k]);
  }
    
  printf("%d\n", A[n-1]);
    
  for(i=1; i<n; i++){
    tmp = A[i];
    j = i-1;
    
    while(j>=0){
      if(A[j]>tmp){
	v = A[j+1];
	A[j+1] = A[j];
	A[j] = v;
      }
      j--;
      /*A[j+1] = tmp;*/
    }
    
    
    for(k=0; k<n-1; k++){
      printf("%d ", A[k]);
    }
    
    printf("%d\n", A[n-1]);
    
  }
  
  
}


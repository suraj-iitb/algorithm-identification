#include<stdio.h>
#define N 100

int main(){
  int i,j,n,A[N],v,x;

  scanf("%d",&n);
 
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  
  for(x = 0 ; x < n ; x++){
    printf("%d",A[x]);
    if(x < n-1) printf(" ");
  }
    printf("\n");
  
  for(i = 1 ; i < n ; i++){
    v = A[i];
    j = i - 1;
    
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(x = 0 ; x < n ; x++){
      printf("%d",A[x]);
      if(x < n-1) printf(" ");
    }
    printf("\n");
    
  }
  return 0;
}

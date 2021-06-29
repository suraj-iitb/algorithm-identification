#include <stdio.h>

int main(){

  int h,i,j,v,N;
  int A[1000];

  scanf("%d",&N);
  
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i == N-1)printf("\n");
    else printf(" ");
  }
  
  for(i = 1; i < N; i++){
    v = A[i];
    j = i - 1;
 
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;      
    }
    A[j+1] = v;
    for(h = 0; h < N; h++){
      printf("%d",A[h]);
      if(h == N-1)printf("\n");
      else printf(" ");
    }
  }
  return 0;
}

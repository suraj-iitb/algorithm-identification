#include<stdio.h>
#define N 1000

int main(){
  int i,j = 0,l,m,A[N],v;
  
  scanf("%d",&j);
  for(i = 0;i < j;i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0;i < j;i++){
    v = A[i];
    m = i-1;
    while(m >= 0 && A[m] > v){
      A[m+1] = A[m];
      m--;
      A[m+1] = v;
    }
    
    for(l = 0; l <  j; l++){
      printf("%d",A[l]);
       if(l != j-1)printf(" ");
    }
    printf("\n");
  }
  return 0;
}


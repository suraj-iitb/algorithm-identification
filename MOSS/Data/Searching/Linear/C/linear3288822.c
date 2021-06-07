#include <stdio.h>

int main() {

  int a,b,i,j,A[10000],B[500],count=0;

  scanf("%d",&a);
  for(i = 0; i < a; i++) {
    scanf("%d",&A[i]);
      }
  scanf("%d",&b);
  for(i = 0; i < b; i++) {
    scanf("%d",&B[i]);
      }

  
  for(i = 0; i < b; i++) {
    for(j = 0; j < a; j++){
      if(B[i] == A[j]) {
	count++;
	break;
      }
    }
  }

 
    
  printf("%d\n",count);
  
  return 0;
}


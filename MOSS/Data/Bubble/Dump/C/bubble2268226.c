#include <stdio.h>

static const int N = 1000;

int main(){
  int i, j, A[N], length, swap, count = 0;

  scanf("%d",&length);
  for(i = 0; i < length; i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0; i < length-1; i++){
    for(j = length-1; j >= i+1; j--){
      if(A[j] < A[j-1]){
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	count++;
      }
    }
  }

  for(i = 0; i < length; i++){
    printf("%d",A[i]);
    if(i <= length-2) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

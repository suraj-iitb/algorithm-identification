#include<stdio.h>
#include<stdlib.h>

static const int N = 100;

int main(){
  int length, i, j,tmp,count=0;
  int A[N];
  
  scanf("%d", &length);
  
  if(length < 1 || length > 100){
    exit(1);
  }

  for ( i = 0; i < length; i++ ){
    scanf("%d", &A[i]);
  }

  for(i = 0; i < length-1; i++){
    for(j = length-1; j > i; j--){
      if(A[j] < A[j-1]){
	count++;
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
      }
    }
  }

  for(i = 0; i < length; i++){
    printf("%d",A[i]);
    if(i == length-1){
      printf("\n");
      break;
    }
    printf(" ");
  }
  printf("%d\n",count);

  return 0;
}

#include <stdio.h>

static const int N = 1000;

int main(){
  int i, j, A[N], length, swap, count = 0, mini;

  scanf("%d",&length);
  for(i = 0; i < length; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i <= length-2; i++){
    mini = i;
    for(j = i; j <= length-1; j++){
      if(A[j] < A[mini]){
	mini = j;
      }
    }
    swap = A[i];
    A[i] = A[mini];
    A[mini] = swap;
    if(A[i] < A[mini]) count++;
  }

  for(i = 0; i < length; i++){
    printf("%d",A[i]);
    if(i <= length-2) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

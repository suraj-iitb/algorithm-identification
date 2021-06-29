#include<stdio.h>
#include<stdlib.h>

static const int N = 100;

int main(){
  int length, i, j, mini, tmp, count=0, flag=0;
  int A[N];
  
  scanf("%d", &length);
  
  if(length < 1 || length > 100){
    exit(1);
  }

  for ( i = 0; i < length; i++ ){
    scanf("%d", &A[i]);
  }

  for(i = 0; i <= length-1; i++){

    mini = i;
    flag = 0;

    for(j = i; j <= length-1; j++){
      if(A[j] < A[mini]){
	mini = j;
	flag = 1;
      }
    }
    if(flag == 1){
      count++;
      tmp = A[i];
      A[i] = A[mini];
      A[mini] = tmp;
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

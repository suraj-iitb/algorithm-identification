#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int main(){

  int i;
  int j;
  int A[MAX];
  int v;
  int length;
 
  scanf("%d",&length);

  if(length > 100){
    printf("too large\n");
    exit(1);
  }

  for(i = 0;i < length;i++){
    scanf("%d",&A[i]);
  }
  for(i = 1;i <= length-1;i++){

    for(j = 0;j < length-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[length-1]);

    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

  }

    for(j = 0;j < length-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[length-1]);

  return 0;

}

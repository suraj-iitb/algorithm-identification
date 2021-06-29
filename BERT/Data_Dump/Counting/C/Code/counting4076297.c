#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define SEQMAX 10001

int main(){

  int n, i, j;
  int count[SEQMAX];
  int *num1, *num2;

  scanf("%d",&n);

  num1 = malloc(sizeof(int) * n+1);
  num2 = malloc(sizeof(int) * n+1);

  for(i = 0; i <= SEQMAX; i++){
    count[i] = 0;
  }

  for(i = 0; i < n; i++){
    scanf("%d",&num1[i+1]);
    count[num1[i+1]]++;
  }

  for(i = 1; i <= SEQMAX; i++){
    count[i]+=count[i-1];
  }

  for(j = 1; j <= n; j++){
    num2[count[num1[j]]] = num1[j];
    count[num1[j]]--;
    }
  
  for(i = 1; i <= n; i++){
    if(i > 1) printf(" ");
    printf("%d",num2[i]);
  }
  printf("\n");

  return 0;
}


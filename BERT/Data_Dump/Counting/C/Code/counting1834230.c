#include<stdio.h>
#include<stdlib.h>

#define MAX 10000


int main(){

  unsigned short *arr, *p;

  int n, i, j;

  scanf("%d",&n);
  arr = malloc(sizeof(short)*n+1);
  p = malloc(sizeof(short)*n+1);
  int c[MAX+1];  

  for( i = 0; i <= MAX; i++)
    c[i] = 0;

  for( i = 0; i < n; i++){
    scanf("%d", &arr[i+1]);
    c[arr[i+1]]++;
  }

  for( i = 1; i <= MAX; i++)
    c[i] = c[i] + c[i - 1];

  for( i = 1; i <= n; i++){
    p[c[arr[i]]] = arr[i];
    c[arr[i]]--;
  }

  for( i = 1; i <= n; i++){

    printf("%d",p[i]);

    if(i != n)
      printf(" ");
  }
  printf("\n");

  return 0;

}

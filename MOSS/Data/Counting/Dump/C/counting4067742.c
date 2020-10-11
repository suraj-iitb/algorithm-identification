#include <stdio.h>
#include <stdlib.h>
#define N 2000001
#define A 10000

int main(){
  int n,i;
  int *a,*b;
  int c[A+1];

  scanf("%d",&n);
  a = (int *)malloc(1 + n * sizeof(int));
  b = (int *)malloc(1 + n * sizeof(int));
  for(i = 0;i <= A;i++){
    c[i] = 0;
  }
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
    c[a[i]]++;
  }
  
  for(i = 1;i <= A;i++) c[i] = c[i] + c[i-1];
  
  for(i = n-1;i >= 0;i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
  for(i = 1;i <= n;i++){
    if(i != 1) printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");

  return 0;
}


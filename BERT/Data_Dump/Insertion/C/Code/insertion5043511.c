#include <stdio.h>
#include <stdlib.h>
#define N 100
#define NUM 1000

int main(){
  int n, i, j, v, k, a[NUM];
  scanf("%d", &n);
  if(n > N){
   printf("error!");
   exit(1);
 }
  for(k = 0; k < n; k++)
    scanf("%d", &a[k]);
  for(k = 0; k < n-1; k++)
    printf("%d ", a[k]);
    printf("%d\n", a[n-1]);
  for(i=1; i<n; i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    for(k = 0; k < n-1; k++)
      printf("%d ", a[k]);
    printf("%d\n",a[n-1]);
  }
  return 0;
}


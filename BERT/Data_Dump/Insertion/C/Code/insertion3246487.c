#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void){
  int i, j, n, *a, v;

  scanf("%d",&n);
  a = malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d", &a[i]);

  for(i=0;i<n;i++){
    v = a[i];
    j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(j=0;j<n;j++){
      printf("%d",a[j]);
      if(j==n-1) printf("\n");
      else printf(" ");
    }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void){
  int n, flag, *a, j, t, i, counter=0;

  scanf("%d",&n);
  a = malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  flag = 1;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if(a[j] < a[j-1]) {
	t = a[j]; a[j] = a[j-1]; a[j-1] = t;
	flag = 1;
	counter++;
      }      
    }
  }

  for(j=0;j<n;j++){
    printf("%d",a[j]);
    if(j==n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",counter);
  return 0;
}

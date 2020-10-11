#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void){
  int i, j, n, *a, mini, t, counter = 0;

  scanf("%d",&n);
  a = malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d", &a[i]);

  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(a[j] < a[mini])mini = j;
    }
    if(i != mini) counter++;
    t = a[i]; a[i] = a[mini]; a[mini] = t; 
  }

  for(j=0;j<n;j++){
      printf("%d",a[j]);
      if(j==n-1) printf("\n");
      else printf(" ");
  }
  printf("%d\n",counter);

  return 0;
}

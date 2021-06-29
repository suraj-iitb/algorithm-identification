/*Insertion Sort*/
#include <stdio.h>
#include <stdlib.h>
#define N 1000
int main (){
  int i, j, k, v, n, tmp, a[N];
  
  scanf("%d", &n);

  for (i=0; i<n; i++)
    scanf("%d", &a[i]);
  
  for(k=0; k<n; k++){
    if (k == n-1){
      printf("%d", a[k]);
      break;
    }
    printf("%d ", a[k]);
  }
  printf("\n");

  for (i=1; i<n; i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(k=0; k<n; k++){
      if (k == n-1){
	printf("%d", a[k]);
	break;
      }
      printf("%d ", a[k]);
    }
    printf("\n");
  }
  return 0;
}


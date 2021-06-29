#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  int j;
  int n;
  int key;
  int *a;

  /* input the array length */
  scanf("%d", &n);

  a = (int *)malloc(n * sizeof(int));

  /* make an array */
  for(i = 0; i < n; i++) {
    scanf("%d" ,&a[i]);
    printf("%d", a[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n");

  /* sorting */
  for(i = 1; i < n; i++) {
    key = a[i];
    /* insert a[i] into the sorted sequence a[0,....,j-1] */
    j = i - 1;
    while((j >= 0) && (a[j] > key)) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;

    /* print the array*/
    for(j = 0; j < n; j++) {
      printf("%d", a[j]);
      if(j != n-1) printf(" ");
    }
    printf("\n");
    
  }
  
  return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main() {
  int i,j;
  int key;
  int n;
  int *array;

  //Initial
  scanf("%d",&n);

  array = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d",&array[i]);
  }
  //printf("\n");

  //sort start
  for(i=0;i<n-1;i++) {
    printf("%d ",array[i]);
  }
  printf("%d\n",array[n-1]);

  for(j=1;j<n;j++) {
    key = array[j];
    i=j-1;
    for(i=j-1;i>=0;i--) {
      if(array[i+1]<array[i]) {
        array[i+1] = array[i];
        array[i] = key;
      }
    }


    for(i=0;i<n-1;i++) {
      printf("%d ",array[i]);
    }
    printf("%d\n",array[n-1]);
  }
  return 0;
}


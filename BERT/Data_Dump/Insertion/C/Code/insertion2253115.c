#include <stdio.h>

int main(){
  int i, j, n, key, array[100];

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &array[i]);

  for(j=0; j<n; j++){
    if(j==n-1) printf("%d", array[j]);
    else printf("%d ", array[j]);
  }
  printf("\n");
  
  for(i=1; i<n; i++){
    key = array[i];
    for(j=i-1; j>=0 && array[j]>key; j--)
      array[j+1]=array[j];
    array[j+1] = key;
    for(j=0; j<n; j++){
      if(j==n-1) printf("%d", array[j]);
      else printf("%d ", array[j]);
    }
    printf("\n");
  }

  return 0;
}

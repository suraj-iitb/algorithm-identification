#include <stdio.h>
int main(){

  int n, a[100], i, j, min, count=0, temp;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=0; i<n; i++){
    min=i;
    for(j=i; j<n; j++){
      if(a[j]<a[min]){
        min=j;
      }
    }
    if(min!=i){
      count++;
      temp=a[min];
      a[min]=a[i];
      a[i]=temp;
    }
  }

  for(i=0; i<n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], count);

  return 0;
}


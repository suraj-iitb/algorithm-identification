#include <stdio.h>
#define N 100

main(){
  int n, a[N], i, j, key;
  scanf("%d", &n);
  for(i =  0;i < n;i++){
    scanf("%d", &a[i]);
  }
  for(i = 1;i < n;i++){
    for(j = 0;j < n-1;j++){ 
      printf("%d ", a[j]); 
    }
    printf("%d\n", a[n-1]); 
    key = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
      a[j+1] = key;
    }
  }
  for(j = 0;j < n-1;j++){ 
    printf("%d ", a[j]); 
  } 
  printf("%d\n", a[n-1]);
  return 0;
}

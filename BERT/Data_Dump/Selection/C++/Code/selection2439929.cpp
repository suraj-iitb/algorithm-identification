#include <stdio.h>
#define N 101

int main() {
  int n, i, j, a[N], flag=0,min, count=0, temp;
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(i = 0; i < n; i++) {
    min = i;
    for( j = i; j < n; j++){
      if(a[min] > a[j]){
        min = j;
        flag = 1;
      }
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
    if(flag) {
      count++;
      flag = 0;
    }
  }
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

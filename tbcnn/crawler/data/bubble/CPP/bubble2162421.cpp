#include "stdio.h"

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  int flag = 1;
  int count = 0;
  while(flag){
    flag = 0;
    for(int j=n-1; j>0; j--){
      int tmp;
      if(a[j]<a[j-1]){
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
        count++;
        flag = 1;
      }
    }
  }
  for(int i=0; i<n; i++){
    if(i>0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}

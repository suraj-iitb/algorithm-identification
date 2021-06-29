#include <stdio.h>
#define N 101

int main() {
  int flag=1, n, i, j, temp, a[N],count=0;
  scanf("%d",&n);

  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  while(flag) {
    flag = 0;
    for(j = n - 1; j >= 0; j-- )
    if(a[j] < a[j-1]){
      temp = a[j];
      a[j] = a[j-1];
      a[j-1] = temp;
      count++;
      flag = 1;
    }
  }

  for(i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i < n-1) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}

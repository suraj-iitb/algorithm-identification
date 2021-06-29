#include <stdio.h>

int main(void) {
  int i,j,n,a[101],sub[2];
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&a[i]);
  for(i = 0; i < n; i++){
    for(j = i - 1; j >= 0; j--){
      if(a[j + 1] < a[j]){
        sub[1] = a[j];
        sub[0] = a[j + 1];
        a[j] = sub[0];
        a[j + 1] = sub[1];
      }
      else break;
    }
    for(j = 0; j < n; j++){
      if(j != 0)putchar(' ');
      printf("%d",a[j]);
    }
    putchar('\n');
  }
}

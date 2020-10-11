#include <stdio.h>

int main(void) {
  int n,a[101],i,j,z = 0,change;
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&a[i]);
  for(i = 0; i < n; i++){
    for(j = n - 1; j >= i + 1; j--){
      if(a[j] < a[j - 1]){
        change = a[j];
        a[j] = a[j - 1];
        a[j - 1] = change;
        z++;
      }
    }
  }
  for(i = 0; i < n; i++){
    if(i != 0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",z);
  return 0;
}

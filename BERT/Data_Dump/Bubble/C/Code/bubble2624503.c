#include <stdio.h>

int main(){
  int c=0, t, j, f, n, a[100];
  scanf("%d", &n);
  for(j = 0; j < n; j++) scanf("%d", &a[j]);
  do{
    f = 0;
    for(j = n-1; j > 0; j--){
      if(a[j] < a[j-1]){
        t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
        f++;
        c++;
      }
    }
  } while(f);
  for(; j < n-1; j++) printf("%d ", a[j]);
  printf("%d\n%d\n", a[j], c);
return 0;
}

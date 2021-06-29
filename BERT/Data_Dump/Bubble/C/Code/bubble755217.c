#include<stdio.h>

int main(int argc, char* argv[])
{
  int a[200], n, swc;
  int i, j, w;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }

  swc = 0;
  for(i = 1; i <= n; i++){
    for(j = n; i + 1 <= j; j--){
      if(a[j] < a[j-1]){
        w = a[j-1];
        a[j-1] = a[j];
        a[j] = w;
        swc++;
      }
    }
  }
  for(i = 1; i < n; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
  printf("%d\n", swc);
  return(0);
}

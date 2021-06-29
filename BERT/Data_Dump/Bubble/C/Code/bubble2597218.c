#include<stdio.h>

int main(){
  int i, j, n, v, count = 0;
  int a[100];

  scanf("%d", &n);
  for ( i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  
  for ( i = 0; i < n; i++){
    for ( j = n - 1; j > 0; j--)
      if(a[j] < a[j - 1]){
        v = a[j];
        a[j] = a[j - 1];
        a[j - 1] = v;
        count++;
      }
  }
  for ( i = 0; i < n; i++){
    if (i > 0)
      printf(" ");
    printf("%d", a[i]);
  }

    printf("\n%d\n", count);

  return 0;
}

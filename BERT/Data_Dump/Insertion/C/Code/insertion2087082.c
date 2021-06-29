#include<stdio.h>

int main(){
  int n;
  scanf("%d\n", &n);
  int a[n], i, k;
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(i = 1; i < n; i++){
    
    for(k = 0; k < n - 1; k++)
      printf("%d ", a[k]);
    printf("%d\n", a[n-1]);
    
    int v = a[i];
    int j = i - 1;
    while( j >= 0 && a[j] > v){
      a[j + 1] = a[j];
      j--;
    }
    a[j+1] = v;
  }

  for(k = 0; k < n - 1; k++)
      printf("%d ", a[k]);
    printf("%d\n", a[n-1]);
  
  return 0;
}

#include <stdio.h>

int main(){
  int n, i, j, k, key;
  scanf("%d\n",&n);
  int a[n];
  for (i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  for (i = 1; i <= n; i++){
    for (k = 0; k < n-1; k++){
      printf("%d ", a[k]);
    }
    printf("%d\n",a[k]);
    key = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }
}


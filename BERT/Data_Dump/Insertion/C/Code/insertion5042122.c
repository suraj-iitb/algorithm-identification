#include <stdio.h>

int main(){
  int i, j, n, v, a[100];

  scanf("%d", &n);
  for(j=0; j<n; j++)
    scanf("%d", &a[j]);
  for(j=0; j<n; j++)
    printf("%d%c", a[j], j==n-1 ? '\n' : ' ');

  for(i=1; i<=n-1; i++){
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    for(j=0; j<n; j++)
      printf("%d%c", a[j], j==n-1 ? '\n' : ' ');
  }
  return 0;
}


#include <stdio.h>

int a[2000001], b[2000001], c[10001];

int main(){
  int i, j, n;

  scanf("%d", &n);
  for(j=1; j<=n; j++)
    scanf("%d", &a[j]);
  
  for(i=0; i<=10000; i++)
    c[i] = 0;
  for(j=1; j<=n; j++)
    c[a[j]]++;
  for(i=1; i<=10000; i++)
    c[i] = c[i] + c[i-1];
  for(j=n; j>=1; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

  for(i=1; i<n; i++)
    printf("%d ", b[i]);
  printf("%d\n", b[i]);

  return 0;
}


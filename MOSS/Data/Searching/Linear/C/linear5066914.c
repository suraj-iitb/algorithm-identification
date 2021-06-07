#include <stdio.h>
#include <stdlib.h>

int main() {
  int cnt=0, i, j, *a, t, n, q;

  scanf("%d", &n);
  a = (int*)malloc(sizeof(int)*n+1);
  for(i=0;i<n;i++) scanf("%d", &a[i]);

  scanf("%d", &q);
  for(i=0;i<q;i++) {
    scanf("%d", &t);
    j = 0;
    a[n] = t;
    while(a[j]!=t) j++;
    if(j!=n) cnt++; 
  }

  printf("%d\n", cnt);
  
  free(a);
  return 0;
}


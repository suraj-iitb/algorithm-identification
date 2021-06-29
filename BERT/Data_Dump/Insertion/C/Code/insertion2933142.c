#include <stdio.h>
#include <stdlib.h>

int main() {

  int *a;
  int i, j,k;
  int n;
  int v;

  /* 確保する要素数をscan */
  scanf("%d", &n);

  a = (int *)malloc(n * sizeof(int)); //メモリ領域の確保

  for (i=0; i<n; i++)
    scanf("%d", &a[i]);


  for (i=0; i<n; i++) {
    if(i != n-1 )printf("%d ", a[i]);
    else if(i == n-1 ) printf("%d", a[i]);

  }
      printf("\n");
  
  
  /* sort */
  for (i=1; i<n; i++) {
    v = a[i];
    j = i-1;

    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }

    a[j+1] = v;

    for (k=0; k<n; k++) {
      if(k != n-1) printf("%d ", a[k]);
      else if(k == n-1) printf("%d", a[k]);
    }
    printf("\n");
  }

    
  free(a);
  return 0;
}


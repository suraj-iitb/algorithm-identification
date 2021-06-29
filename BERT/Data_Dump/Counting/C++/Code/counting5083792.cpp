#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,i,j;
  int *a, *b, *c;
  int k=0;

  scanf("%d",&n);
  a = (int *)malloc(sizeof(int) * (n+1));
  b = (int *)malloc(sizeof(int) * (n+1));
  for(i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
  }

  for(i = 1 ; i <= n ; i++){
    if(a[i] > k) k = a[i];
  }

  c = (int *)malloc(sizeof(int) * (k + 1));

  for(i = 0 ; i <= k ; i++){
    c[i] = 0;
  }


  for(j = 1 ; j <= n ; j++){
    c[a[j]]++;
  }

  for(i = 1 ; i <= k ; i++){
    c[i] = c[i] + c[i-1];
  }

  for(j = n ; j > 0 ; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

  for(i = 1 ; i < n ; i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[n]);

  free(a);
  free(c);
  return 0;
}


#include <stdio.h>
#define N 100

int main(){

  int i, j;
  int n, minv, tmp, a[N];
  int count = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n; i++){
    minv = i;

    for(j = i; j < n; j++){
      if(a[j] < a[minv]){
	minv = j;
      }
    }

    if(i != minv){
      tmp = a[i];
      a[i] = a[minv];
      a[minv] = tmp;
      count++;
    }

  }

   for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n - 1) printf(" ");
  }

   printf("\n%d\n", count);

   return 0;
}

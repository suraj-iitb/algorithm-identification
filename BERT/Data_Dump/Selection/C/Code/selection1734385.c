#include <stdio.h>
#define N 100

int main()
{
  int a[N], n, c=0, x = 0, i, j, minj=0;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=0; i<n; i++){
    minj=i;
    for(j=i; j<n; j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(i != minj){
    x = a[i];
    a[i] = a[minj];
    a[minj] = x;
    c++;
    }
  }

  for(i=0; i<n; i++){
    printf("%d", a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n", c);

  return 0;
}

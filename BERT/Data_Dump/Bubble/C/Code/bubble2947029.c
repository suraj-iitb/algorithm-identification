/*バブルソート*/
#include <stdio.h>
#define N 100
int main(){
  int a[N], n, i, j, count=0, flag=1, tmp;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  i=0;
  while(flag){
    flag=0;
    for (j=n-1; j>i; j--){
      if (a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	count++;
	flag = 1;
      }
    }
    i++;
  }

  for (i=0; i<n; i++){
    if (i==n-1){
      printf("%d\n", a[i]);
      break;
    }
    printf("%d ", a[i]);
  }

  printf("%d\n", count);

  return 0;
}
  


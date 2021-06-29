#include <stdio.h>
#define N 100

main(){
  int n, a[N], i, j, minj, conut = 0, b, c;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
  }
  for(i = 0;i < n;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    if(i != minj){
      b = a[i];
      c = a[minj];
      a[i] = c;
      a[minj] = b;
      conut++;
    }
  }
  for(i = 0;i < n-1;i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n-1]);
  printf("%d\n", conut);
  return 0;
}

#include <stdio.h>
#define N 100

main(){
  int n, a[N], i, flag, conut = 0, b, c;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
  }
  flag = 1;
  while(flag){
    flag = 0;
    for(i = n-1;i >= 1;i--){
      if(a[i] < a[i-1]){
	b = a[i];
	c = a[i-1];
	a[i] = c;
	a[i-1] = b;
	flag = 1;
	conut++;
      }
    }
  }
  for(i = 0;i < n-1;i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n-1]);
  printf("%d\n", conut);
  return 0;
}

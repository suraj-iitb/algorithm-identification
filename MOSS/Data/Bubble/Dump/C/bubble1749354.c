#include <stdio.h>
#define N 100

int main(){

  int i;
  int n, a[N], tmp;
  int sum = 0, flag = 1;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  while(flag){
    flag = 0;

    for(i = n - 1; i > 0; i--){
      if(a[i] < a[i - 1]){
	tmp = a[i];
	a[i] = a[i - 1];
	a[i - 1] = tmp;
	flag = 1;
	sum++;
      }

    }

  }

  for(i = 0; i < n; i++){
    printf("%d",a[i]);
    if(i < n - 1) printf(" ");
  }

  printf("\n%d\n", sum);

  return 0;
}

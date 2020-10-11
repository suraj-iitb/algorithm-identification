#include <stdio.h>
#define N_MAX 100

int main()
{
  int i, count = 0, n, tmp, flag = 1, a[N_MAX];

  scanf("%d", &n);
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
	count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n%d\n", count);

  return 0;
}


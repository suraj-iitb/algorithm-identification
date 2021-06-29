#include<stdio.h>
#define N 100

int main(void){
  int i, j, n, tmp, a[N];
  int cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n-1; i++){
    for(j = n-1; j >= i+1; j--){
      if(a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	cnt++;
      }
    }
  }
  
  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
  printf("%d\n", cnt);
  
  return 0;
}


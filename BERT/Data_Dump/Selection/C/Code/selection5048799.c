#include<stdio.h>
#define N 100

int main(void){
  int i, j, n, tmp, mini, a[N];
  int cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      if(a[j] < a[mini]){
	mini = j;
      }
    }
    if(a[i] != a[mini]){
      tmp = a[mini];
      a[mini] = a[i];
      a[i] = tmp;
      cnt++;
    }
  }
  
  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
  printf("%d\n", cnt);
  
  return 0;
}


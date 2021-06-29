#include <stdio.h>
#define N 100

int main(){
  int i, j, k, n, minj = 0, m, con = 0;
  int a[N];

  scanf("%d", &n);

  for(k = 0; k < n; k++){
    scanf("%d", &a[k]);
  }

  for(i = 0; i <= n-1; i++){
    minj = i;
    for(j = i; j <= n-1; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    if(i != minj){
      m = a[i];
      a[i] = a[minj];
      a[minj] = m;
      con++;
    }
  }

  printf("%d", a[0]);
  for(k = 1; k < n; k++){
    printf(" %d", a[k]);
  }
  printf("\n%d\n", con);

  return 0;
}


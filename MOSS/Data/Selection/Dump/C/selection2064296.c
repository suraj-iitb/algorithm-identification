#include <stdio.h>

int main(){

  int a[100], i, N, exc, d, j, minj;

  scanf("%d", &N);

  for(i = 0; i <= N - 1; i++){
    scanf("%d", &a[i]);
  }

// Selection Sort(A,N)
  exc = 0;
  for (i = 0; i <= N - 1; i++ ){
    minj = i;
    for (j = i; j <= N - 1; j++){
      if (a[j] < a[minj]){
        minj = j;
      }
    }
    if(i != minj){
      exc++;
    }
    d = a[i];
    a[i] = a[minj];
    a[minj] = d;
  }

  for(i = 0; i <= N - 2; i++){
    printf("%d ", a[i]);
  }

  printf("%d\n%d\n",a[N-1], exc);

  return 0;
}

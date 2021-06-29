#include <stdio.h>

int main(){
  int a[100];
  int i, j, minj, n;

  int data, c, cnt = 0;

  scanf("%d", &n);

  if(n < 1 || n > 100) return 0;

  for(c = 0; c < n; c++){
    scanf("%d", &a[c]);
  }

  for(i = 0; i < n; i++){
    minj = i;

    for(j = i; j < n; j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }

    data = a[i];

    a[i] = a[minj];
    a[minj] = data;

    if(i != minj){
      cnt++;
    }
  }

  for(c = 0; c < n-1; c++){
    printf("%d ", a[c]);
  }

  printf("%d\n", a[n-1]);
  printf("%d\n", cnt);



  return 0;
}


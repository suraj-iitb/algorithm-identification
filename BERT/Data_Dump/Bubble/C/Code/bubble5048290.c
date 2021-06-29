#include <stdio.h>

int main(){
  int i, j, n, c;
  int cnt = 0;
  int data;

  int a[100];

  scanf("%d", &n);

  for(c = 0; c < n; c++){
    scanf("%d", &a[c]);
  }

  for(i = 0; i < n-1; i++){
    for(j = n-1; j >= i + 1; j--){
      if(a[j] < a[j-1]){
        data = a[j];
        a[j] = a[j-1];
        a[j-1] = data;

        cnt++;
      }
    }
  }

  for(c = 0; c < n-1; c++){
    printf("%d ", a[c]);
  }

  printf("%d\n", a[n-1]);
  printf("%d\n", cnt);


  return 0;
}


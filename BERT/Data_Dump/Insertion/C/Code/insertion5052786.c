#include<stdio.h>
//挿入サーチ
int main(){
  int i, key, j, x;
  int b[100];

  scanf("%d", &x);
  for (i = 0; i < x; i++) scanf("%d", &b[i]);

//1回もとの状態を出力
  for (i = 0; i < x; i++){
    if (i == x-1) {
      printf("%d\n", b[i]);
      break;
    }
    else printf("%d ", b[i]);
  }

  for(j = 1; j <x; j++){
    key = b[j];
    i = j-1;
    while(i >= 0 && b[i] > key){
      b[i+1] = b[i];
      i--;
      }
    b[i+1] = key;
    for (i = 0; i < x; i++){
      if (i == x-1) {
        printf("%d\n", b[i]);
        break;
      }
      else printf("%d ", b[i]);
    }
  }

  return 0;
}


#include <stdio.h>

int main(void){
  int n, a[100], key, i, j, k;

  /*配列に値を代入する*/
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  /*入力直後の配列の要素の並びを出力する*/
  for(i=0; i<n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[n-1]);

  /*整列処理*/
  for(i=1; i<n; i++){
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
    /*配列の中身を出力する*/
    for(k=0; k<n-1; k++){
      printf("%d ", a[k]);
    }
    printf("%d\n",a[n-1]);
  }

  return 0;
}


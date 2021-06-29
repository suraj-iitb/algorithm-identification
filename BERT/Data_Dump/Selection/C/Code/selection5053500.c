#include <stdio.h>
//sentakusortdayo

int main(){
  int i, j, minj, n, cnt=0, temp;
  int A[100];

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(A[j] < A[minj]) minj = j;
    }
    /*先にcntup,あとから入れ替え処理
    マクロがちゃんと動かなかったので普通に。*/
    if (A[i] > A[minj]) cnt++;
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
      }

  for(i = 0; i < n; i++){
    if (i == n-1){
      printf("%d\n",A[i]);
      break;
    }
    else printf("%d ", A[i]);
  }
  printf("%d\n", cnt);

  return 0;
}


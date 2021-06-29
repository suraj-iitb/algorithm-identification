#include <stdio.h>

int main(void){
  int N, v, i, j, k, m;
  scanf("%d", &N);
  int A[N];

  //配列に入力値を代入する
  for(k = 0; k < N; k++){
    scanf("%d", &A[k]);
  }

  //for文ではiを右にずらし、while文ではソート済みの配列をずらしている
  for(i = 1; i < N; i++){
    
    for(m = 0; m < N; m++){
      if(m > 0) printf(" ");
      printf("%d",A[m]);
    }
    printf("\n");
    
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;


  }

  for(m = 0; m < N; m++){
    if(m > 0) printf(" ");
    printf("%d",A[m]);
  }
  printf("\n");
  return 0;
}


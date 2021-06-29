#include <stdio.h>

void trace(int A[],int N,int count){
  int i ;
  for (i = 0; i < N ; i++){
    if (i > 0) printf(" ");
    printf("%d" , A[i]);
  }
  printf("\n");
  printf("%d\n", count);
}

void selectsort(int A[],int N,int count){
  int i ,j,minj;
  int tmp,cou;

  for(i = 0 ; i < N; i++ ){
    minj = i;
    cou = 0;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;//すでに探索終わってるところ以外の最小探索
        cou = 1;//交換成立の場合カウント１を代入し続ける(実際に交換するのは下で一回だけ)
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    count = count + cou;
  }
  trace(A,N,count);
}


int main(){
  int N,i,count;
  int A[100];

  scanf("%d", &N);
  for(i = 0; i<N; i++)scanf("%d",&A[i] );

  count = 0;
  selectsort(A,N,count);

  return 0;
}

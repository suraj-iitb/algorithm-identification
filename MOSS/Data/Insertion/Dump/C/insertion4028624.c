#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *,int);
  int main(){
    int i,num;//for loop用 個数用
  int *A;//配列用
  scanf("%d",&num);//個数入力
  A = (int *)malloc(sizeof(int *) * num);//配列生成
  for(i=0;i<num;i++){//配列入力 ＆ 表示
    scanf("%d",&A[i]);
    if(i == num-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  insertionSort(A,num);//並び換え ＆ 表示

  free(A);//解放
  return 0;
}

void insertionSort(int *A,int num){
  int i,v,j,k;// i,j,kはloop用、vは退避用
  for(i = 1; i<=num-1;i++){
    v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0;k<num;k++){//表示
      if(k == num-1)printf("%d\n",A[k]);
      else printf("%d ",A[k]);
    }
  }
}

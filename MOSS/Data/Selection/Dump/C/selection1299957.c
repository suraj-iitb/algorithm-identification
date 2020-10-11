#include<stdio.h>

int main(){
  int length; //長さ
  int A[100]; //配列
  int i=0,j=0; //ループ
  int flag=0; //交換回数
  int key; // 回避変数
  int min; //最小値

  scanf("%d",&length); //長さ入力
  
  while(i < length){ //数の入力
    scanf("%d",&A[i]);
    i++;
  }
  
  for(i = 0;i <= length-1;i++){ //selectionSort(A, N)
    min = i;
    for(j = i;j <= length-1;j++){
      if(A[j] < A[min]){
	min = j;
      }
    }
    if(min!=i)flag++;
    key = A[i];
    A[i] = A[min];
    A[min] = key;
  }

  for(i = 0;i < length-1;i++){   //表示
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",flag);
  return 0;
}

#include <stdio.h>

void selection(int n, int data[]){
  int min ;
  int test[100];
  int tmp,key,counter = 0;
  for (int k = 0; k < n; k ++){
        test[k] = data[k];
      }
  //i-nまでのminを探索
  //i:既ソートの右端index
  //j:未ソートの左端index
  for (int i = 0; i < n-1 ; i ++ ){ //未ソートの右端でループ
    min = test[i+1];//既ソートの左端の値をminの初期値に
    key = i+1; // keyの初期化
    for (int j = i+1; j < n; j ++ ){
      //最小値とそのindexの探索
      
      if (test[j]< min){
        min = test[j];
        key = j;
      }
    }
    //既ソートのminが未ソートの右端よりも小さい場合にswap
    if (test[i] > min){
    //data[i]にminを、data[j]にdata[i]を代入
      tmp = test[i];
      test[i] = min;
      test[key] = tmp;
      counter += 1; 
    
    }
  }
  //結果の出力
  for (int i = 0; i < n ; i ++ ){
    if (i > 0) printf(" ");
    printf("%d",test[i]);
  }
  printf("\n");
  printf("%d\n",counter);
}

int main(void){
  //入出力処理
  int n,data[100];
  scanf("%d",&n);
  for (int i = 0; i < n ; i ++ ){
    scanf("%d",&data[i]);
  }
  selection(n,data);
  return 0;
}






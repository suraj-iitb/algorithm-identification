// Insertions Sort

#include <stdio.h>

void printer(int n,int data[]){
  for (int i = 0; i < n; i++ ){
    //左端の場合は空白を入力しない
    if (i > 0) printf(" ");
      printf("%d",data[i]);
  }
}
// Sort func


int sort(int n,int data[]){
  
  //未ソートの開始位置でループ
  int v; // 被ソート要素の値
  int j; // 既ソート位置の右端
  for (int i = 0; i < n; i++){
    
    v = data[i];
    j = i-1;
    //既ソート配列を右にずらす
    while((j >= 0) && (data[j] >= v)){
      data[j+1] = data[j];
      j--;
    }
    //値の挿入
    data[j+1] = v;
    
    printer(n,data);
    printf("\n");
  }
  return 0;
}



int main(){
  int n;
  int data[100];
  //入力値処理
  scanf("%d",&n); // nに入力
  //配列に値を入力
  for (int i = 0; i <= n-1; i++ ){
    scanf("%d",&data[i]);
  }
  //初期配列の表示
  //printer(n,data);
  //printf("\n");
  sort(n,data);
  return 0;

}









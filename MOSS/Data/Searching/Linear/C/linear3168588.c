#include <stdio.h>

//線形探索
int search(int A[], int n, int key){
  int i = 0;
  A[n] = key; //探索対象の配列の最後に番兵をセット
  while(A[i] != key) i++;//見つかったら終了
  return i != n;//見つかったら1が、見つからなかったら0が返却される
}

int main(){
  int i, n, A[10000+1], q, key, sum = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);//全要素を探索対象の配列に格納

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key); //キーワードを取得して
    if(search(A, n, key))//探索を行う(返り値は1か0)
      sum++;
  }

  printf("%d\n", sum);

  return 0;
}

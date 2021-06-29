#include <stdio.h>

int A[1000000], n;

//二分探索
int binarySearch(int key){
  int left = 0;
  int right = n;//要素の数（A[n]には値は入っておらず番兵の役割がある）
  int mid;

  while(left < right){
    mid = (left + right)/2; //midはint型であるから少数部分は切り捨て
    if(key == A[mid]) return 1; //keyを発見
    if(key > A[mid]) left = mid + 1; //もし検索したい値が中央値より大きいならば後半を探索
    else if (key < A[mid])right = mid; //前半を探索
  }
  return 0;//見つからなかった場合
}

int main(){
  int i, q, k, sum = 0;

  scanf("%d", &n);//要素の数
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);//配列Aに値をセット
  }

  scanf("%d", &q);//二つ目の配列の要素数
  for(i = 0; i < q; i++){//二つ目の配列の要素数の分だけループする
    scanf("%d", &k);//値を保存して
    if(binarySearch(k)) sum++;//binarySearchで値が見つかればsumがインクリメントされる
    }
    printf("%d\n", sum);

    return 0;

}

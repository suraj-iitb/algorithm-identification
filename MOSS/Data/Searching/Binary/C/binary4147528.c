//Binary Search 二分探索
#include <stdio.h>

int A[100000];
int n;


int binarySearch( int key );





int main()
{

  int m;
  int key;
  int i;
  int sum=0;

  scanf("%d",&n);
  for( i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&m);
  for( i = 0; i < m; i++){
    scanf("%d",&key);
    if( binarySearch( key )) sum++;
  }

  printf("%d\n",sum);

  return 0;
}
    



int binarySearch( int key ) //半分割って半分値より小さいか大きいかで考える方法
{

  int left = 0;
  int right = n;
  int mid;

  while( left < right ){ //左端が右より小ければループ     
    mid = (left + right) / 2;
    if( A[mid] == key ) return 1; //中間の値が一致すればリターン
    if( key < A[mid])   // 探す値が中間の値より小ければ右端を中間に設定する
      right = mid;
    else                //そうでなければ左端を中間+1に設定
      left = mid + 1;
  }

  return 0;
    
}


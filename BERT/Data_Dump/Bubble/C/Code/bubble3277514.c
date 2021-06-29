#include <stdio.h>

int main(){


  /*1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
    2   flag = 1 // 逆の隣接要素が存在する
    3   while flag
    4     flag = 0
    5     for j が N-1 から 1 まで
    6       if A[j] < A[j-1]
    7         A[j] と A[j-1] を交換
    8         flag = 1
  */


  int n ,i ,j,c=0 , t;
  scanf("%d" ,&n);
  int arr[n];
  for ( i = 0; i < n; i++){
    scanf("%d",&arr[i]);
  }
  
  int flag = 1 ;
  while ( flag){
    flag = 0;
    for ( i = n - 1 ;  i >= 1; i--){
      if ( arr[i] < arr[ i-1 ]){
	t = arr[i]; arr[i] = arr[ i-1 ]; arr[i-1] = t;
	c++;
	flag = 1;
      }
    }
  }

  for ( i = 0; i < n; i++){
    printf("%d",arr[i]);
    if ( i == n-1){printf("\n%d\n",c);}
    else {printf(" ");}
  }
  
  return 0;
}


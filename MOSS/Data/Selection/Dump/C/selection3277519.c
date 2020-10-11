#include <stdio.h>

int main(){

  /*
  1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 0 から N-1 まで
3     minj = i
4     for j が i から N-1 まで
5       if A[j] < A[minj]
6         minj = j
7     A[i] と A[minj] を交換
  */

  int n ,i, min ,j,c=0;
  scanf("%d" ,&n);
  int arr[n];
  for ( i = 0; i < n; i++){
    scanf("%d",&arr[i]);
  }

  for ( i = 0; i < n ;i++){
    min = i;
    for ( j = i; j < n; j++){
      if ( arr[j] < arr[min]){ min = j;}
    }
    if ( arr [i] != arr[min] ){
      c++;
    j = arr[i]; arr[i] = arr [min]; arr[min] = j;
    }
  }

  for ( i = 0; i < n; i++){
    printf("%d",arr[i]);
    if ( i == n-1){printf("\n%d\n",c);}
    else {printf(" ");}
  }
  
  return 0;
}


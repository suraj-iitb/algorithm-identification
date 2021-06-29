#include <stdio.h>
#include <stdlib.h>
#define K 10000  //A[i]最大値

int *countingSort(int*, int); //入力された配列、ソート後の配列、入力の要素数

main(){
  int *arrA, *arrB;
  int n, i;

  scanf("%d", &n);
  arrA = (int *)malloc(sizeof(int)*n);
  for(i=0; i<n; i++) scanf("%d", arrA+i);

  arrB = countingSort(arrA, n);

  for(i=0; i<n-1; i++) printf("%d ", arrB[i]);
  printf("%d\n", arrB[i]);

  return 0;
}

int *countingSort(int *arrA, int n){
  int *arrB, arrC[K+1], i;
  arrB = malloc(sizeof(int)*n);

  arrC[0] = -1;
  for(i=1; i<=K; i++) arrC[i] = 0;
  
  for(i=0; i<n; i++){
    arrC[arrA[i]]++;
  }
  
  for(i=1; i<=K; i++){
    arrC[i] = arrC[i] + arrC[i-1];
  }

  /*  for(i=0; i<=K; i++){
    printf("arrC[%d] = %d\n", i, arrC[i]);
    }*/
  
  for(i=n-1; i>=0; i--){
    arrB[arrC[arrA[i]]] = arrA[i];
    arrC[arrA[i]]--;
  }

  return arrB;
}

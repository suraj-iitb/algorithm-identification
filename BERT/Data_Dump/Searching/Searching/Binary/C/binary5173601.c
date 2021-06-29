#include <stdio.h>

int BinarySearch(int, int *, int);
  
int main(){ //Binary Search
  int S[100000], T[50000];
  int i;
  int n, q;
  int total = 0;

  scanf("%d", &n); /* ここでSの要素数を格納 */
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q); /* ここでTの要素数を格納 */
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  
  for(i = 0; i < q; i++){
    total += BinarySearch(T[i], S, n);
  }

  printf("%d\n", total);
  
  return 0;
}

int BinarySearch(int key, int *array, int n){
  int left = 0;
  int right = n;
  int mid;

  while(left < right){
    mid = (left + right) / 2;
    
    if(array[mid] == key){
      return 1;
    }
    else if(key < array[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
      
  }
  return 0;
}


#include <stdio.h>

int LinearSearch(int, int *, int);
  
int main(){ //Linear Search
  int S[10000], T[500];
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
    total += LinearSearch(T[i], S, n);
  }
  printf("%d\n", total);
  
  return 0;
}

int LinearSearch(int key, int *array, int n){
  int j = 0;
  array[n] = key;

  while(array[j] != key){
    j++;
    if(j == n){
      return 0;
    }
  }
  return 1;
}



#include <stdio.h>
 
int LinearSearch(int A[], int n, int key){

  int i = 0;
  A[n] = key;
  while(A[i] != key){
      i++;
  }

  return i != n;
}
 
int main(){

  int i, n, p, key, sum = 0;
  int A[10000];

  scanf("%d", &n);
  for (i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d", &p);
  for (i = 0; i < p; i++){
    scanf("%d", &key);
    if (LinearSearch(A, n, key) == 1){
      sum++;
    }
  }

  printf("%d\n", sum);

return 0;
}

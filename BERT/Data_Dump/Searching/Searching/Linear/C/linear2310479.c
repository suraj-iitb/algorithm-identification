#include <stdio.h>
#define N 10001

int linearSearch(int A[], int n, int key)
{
  int i;

  i = 0;
  A[n] = key;
  if(A[0] == key){
    return 1;
  }
  while(A[i] != key){
    i++;
  }
  if(i == n){
    return 0;    
  }
  return i;
}

int main(){

  int i, n, q, key, count=0;
  int A[N];
  
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);

  for(i=0; i<q; i++){
    scanf("%d", &key);
    if(linearSearch(A, n, key)){
	count++;
      }
  }

    printf("%d\n", count);

  return 0;
}

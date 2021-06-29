#include <stdio.h>
#define N 1000001

int binarySearch(int A[], int n, int key)
{
  int left=0, right=n, mid;

  while(left < right){
    mid = (left+right) / 2;
    if(A[mid] == key){
      return mid;
    } else if(key < A[mid]){
      right =  mid;
    } else {
      left = mid + 1;
    }
  }
    return 0;
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
    if(binarySearch(A, n, key)){
	count++;
      }
  }

    printf("%d\n", count);

  return 0;
}

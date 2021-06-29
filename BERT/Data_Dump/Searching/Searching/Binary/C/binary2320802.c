#include <stdio.h>
#define MAX 1000000

int binarySearch(int);
int A[MAX];
int n;

int main(){
  int i,q;
  int key,result = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for( i = 0; i < q; i++){
    scanf("%d",&key);
    if(binarySearch(key)){ /**/
      result++;
    }
  }
  printf("%d\n",result);
  //printf("\n");
  return 0;
}

int binarySearch(int key){
  int left = 0, right = n;
  int mid;
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid]){
      return 1;
    }
    if(key > A[mid]){
      left = mid + 1;
    }
    else if(key < A[mid]){
      right = mid;
    }
  }
  return 0;
}

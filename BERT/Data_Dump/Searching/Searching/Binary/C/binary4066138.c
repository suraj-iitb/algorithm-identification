#include <stdio.h>
#define N 100000
int binarySearch();
int S[N], n, key;
int main(){
  int i, q, C=0;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &key);
    if( binarySearch(key) == 1 ){
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}

int binarySearch(){
  int left=0;
  int right=n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key){
      return 1;
    }
    else if(S[mid] > key){
      right = mid;
    }
    else
      left = mid + 1;
  }
  return 0;
}
    




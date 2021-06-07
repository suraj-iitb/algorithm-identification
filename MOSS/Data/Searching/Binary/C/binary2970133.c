#include <stdio.h>
int binarySearch(int *, int, int);

int main(){
  int N[100000]; int Q[50000];
  int nnum, qnum;
  int i, j, count = 0;
  
  scanf("%d", &nnum);
  for(i = 0; i < nnum; i++){
    scanf("%d", &N[i]);
  }
  scanf("%d", &qnum);
  for(i = 0; i < qnum; i++){
    scanf("%d", &Q[i]);
  }
  
  for(i = 0; i < qnum; i++){
    if(binarySearch(N, nnum, Q[i]) == 1){
      count++;
    }
  }
  
  printf("%d\n", count);
  return 0;
}

int binarySearch(int *A, int length, int key){
  int left, right, mid;
  
  left = 0;
  right = length;
  
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid]){
      return 1;
    }
    
    if(key < A[mid]){
      right = mid;
    }
    else {
      left = mid+1;
    }
  }
  
  return 0;
}


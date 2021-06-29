#include<stdio.h>
#define nMAX 100000
#define qMAX 50000

int binarySearch(int, int, int[]);

int main(){
  int i, n, q, S[nMAX], T[qMAX], count = 0;
  
  scanf("%d", &n); 
  
  for(i = 0; i < n; i++) 
    scanf("%d", &S[i]);
  
  scanf("%d", &q); 
  
  for(i = 0; i < q; i++) 
    scanf("%d", &T[i]); 
  
  for(i = 0; i < q; i++){
    if(binarySearch(T[i], n, S) != -1)
      count++;
  }
  
  printf("%d\n", count); 
  
  return 0; 
}

int binarySearch(int key, int n, int A[]){
  int left, right, mid;
  
  left = 0;
  right = n;
  
  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key)
      return mid;
    else if(key < A[mid])
      right = mid;
    else
      left = mid + 1;
  }
  
  return -1;
}


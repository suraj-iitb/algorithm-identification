#include<stdio.h>

#define NMAX 100000

int binarySearch(int[], int, int);

int main(){
  
  int S[NMAX], n, i, q, key;
  int sum = 0;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]); 

  scanf("%d", &q);
  
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    
    if (binarySearch(S, n, key))
      sum++;
  }
  
  printf("%d\n", sum);
  
  return 0;
}

int binarySearch(int S[], int n, int key){
  
  int left = 0;
  int right = n;
  int mid;
  
  while(left < right){
    mid = (left + right) / 2;
    
    if(S[mid] == key)
      return 1;

    else if(key < S[mid])
      right = mid;
    
    else left = mid + 1; 
  }
  return 0;
}



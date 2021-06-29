#include <stdio.h>

int A[1000000];

int biNsearch(int,int);

int main(){
  
  
  int i,q,n,key1;
  int count = 0;
  
  scanf("%d", &n);
  
  for(i = 0;i < n;i ++){
    scanf("%d",&A[i]);
  }
  
  scanf("%d",&q);
  
  for(i = 0;i < q;i ++)
    {
      scanf("%d", &key1);
      if(biNsearch(key1,n))count ++;
    }

  printf("%d\n",count);

  return 0;
}

int biNsearch(int key2,int n){

  int left = 0,right = n;
  int mid;
  
  
  while(left < right) {
    
    mid = (left + right) / 2;
    
    if (key2 == A[mid]) {
      return 1;
    }
    
    if(key2 > A[mid]){
      left = mid + 1; 
    }
    else if(key2 < A[mid])
      {
      right = mid; 
      }
  }  
    return 0;
  
}

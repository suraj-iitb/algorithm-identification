#include <stdio.h>

int binarySearch(int,int);

int T[100000],S[500000];

int main() {

  int n,q,i,x,key,count=0;
    
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++) {
    scanf("%d",&T[i]);
  }
  for(i = 0; i < q; i++) {
    x = binarySearch(n,T[i]);
   
    if(x != -1) count++;
  }
  
  printf("%d\n",count);
  return 0;
}

int binarySearch(int n,int key)
{
  int left,right,mid;
  left = 0;
  right = n;
  
  while(left < right) {
    mid = (left + right)/2;
    if(key == S[mid])
      return mid;
    
    else if(key > S[mid])
      left = mid + 1;
    
    else if(key < S[mid])
      right = mid;
  }
    return -1;   
}


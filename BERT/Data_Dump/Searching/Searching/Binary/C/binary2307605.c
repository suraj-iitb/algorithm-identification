#include <stdio.h>
#define MAX 1000000
int binarySearch(int, int);
int S[MAX],T[MAX];
int main(){
  int n,q,i,j,count=0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    
  }

  for(i = 0; i < q; i++){
    count = count + binarySearch(T[i],n);
  }
  
  

  printf("%d\n",count);

  return 0;
}

int binarySearch(int key, int n){
  int left,right,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key){
      return 1;
    }
    else if(key < S[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return 0;
}

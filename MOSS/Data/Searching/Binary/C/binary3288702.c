#include<stdio.h>
#define N 100000

int S[N];

int main(){
  int n,i,q,key,result;
  int sum = 0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);
    result = binarySearch(key, n);
    if(result == 1){
      sum++;
    }
  }

  printf("%d\n",sum);

  return 0;
  
  
}

int binarySearch(int key, int n){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key)
      return 1;
    else if(key < S[mid]){
      right = mid;
    }else{
      left = mid + 1;
    }
  }
  return 0; //Not Found
}


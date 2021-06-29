#include <stdio.h>
#define N 100000

int n,S[N];

int binarySearch(int key){
  int left=0,right=n,mid;
  while(left < right){
    mid = (left+right)/2;
    if(key == S[mid]) return 1;
    if(key > S[mid]) left = mid+1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}

int main(){
  int i,q,k,count=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&k);
    if(binarySearch(k)) count++;
  }

  printf("%d\n",count);
  return 0;
}

    

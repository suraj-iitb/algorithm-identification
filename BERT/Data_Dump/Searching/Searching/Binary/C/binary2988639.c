#include <stdio.h>
int S[1000000],n;
int binarySearch(int key){
  int left =0;
  int right,mid;
  right=n;
  while(left < right){
    mid = (left+right)/2;
    if(S[mid] == key)return 1;
    else if(key < S[mid])right =mid;
    else left=mid+1;
  }
  return 0;
}
int main(){
  int i,q,key,count=0;
    
  scanf("%d",&n);
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i < q;i++){
    scanf("%d",&key);
    if(binarySearch(key))count++;
  }
  printf("%d\n",count);
  return 0;
}


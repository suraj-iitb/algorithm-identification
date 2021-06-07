#include <stdio.h>

int binarysearch(int key,int S[],int n){
  int i,left=0,right=n,mid;
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

int main(){
  int i,n,S[1000000],q,T[50000],ans=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<q;i++){
    if(binarysearch(T[i],S,n) == 1)
      ans++;
  }
  printf("%d\n",ans);
  return 0;
}


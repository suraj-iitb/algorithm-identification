#include <stdio.h>

int binarySearch(int *,int,int);

int main(){
  int i ,S[100000],q,t,c=0,n;
  scanf("%d",&n);
  for(i=0 ; i<n ; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
    scanf("%d",&t);
    if(binarySearch(S,t,n)==1)c++;
  }
  printf("%d\n",c);
  return 0;
}

int binarySearch(int *S,int t,int n){
  int right = n,left = 0,mid;
  while(left < right){
    mid = (left+right) / 2;
    if(S[mid] == t)
      return 1;
    else if(t < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return 0;
}


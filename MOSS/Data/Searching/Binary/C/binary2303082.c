#include <stdio.h>
#define N 10000000
#define Q 10000000
int binarySearch(int);
int i,j,n,q,S[N],T[Q],c=0;
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  for(i=0;i<q;i++) c+=binarySearch(T[i]);
  printf("%d\n",c);
  return 0;
}
int binarySearch(int key){
  int left,right,mid;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key) return 1;
    else if(key<S[mid]) right=mid;
    else left=mid+1;
  }
  return 0;
}

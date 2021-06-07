#include<stdio.h>
#include<stdlib.h>

#define N 100000
#define Q 50000
int n,S[N];

int binarySearch(int);
main(){
  int i,T[Q],s=0,q;
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  for(i=0;i<q;i++){
   s+= binarySearch(T[i]);
  }
  printf("%d\n",s);
  return 0;
}
 
int binarySearch(int key){
  int left=0,right,mid;
  
  right = n;
  while(left<right){
    mid = (right + left) / 2;
    if(key == S[mid]) return 1;
    if(key > S[mid]) left = mid+1;
    else if(key < S[mid]) right = mid;
  }
  return 0;
}

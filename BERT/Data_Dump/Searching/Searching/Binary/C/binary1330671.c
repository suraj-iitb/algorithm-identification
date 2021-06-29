#include <stdio.h>
#define N 100000
#define M 50000

int binarySearch(int);
int S[N],n;
 
main(){
  int i,j,q,T[M],C=0;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
 
  for(i=0;i<q;i++){
    C+=binarySearch(T[i]);
  }
 
  printf("%d\n",C);
  return 0;
}
 
int binarySearch(int key){
  int left,right,mid;
 
  left=0;
  right=n;
  while(left < right){
    mid=(left + right)/2;
  if(key == S[mid]) return 1;
  if( key > S[mid]) left = mid + 1;
  else if(key < S[mid]) right = mid; 
  }
  return 0;
}
  

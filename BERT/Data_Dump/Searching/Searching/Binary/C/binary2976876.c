#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
#define N 100000
#define Q 50000
 
int binarySearch(int*, int);
int n;
 
int main(){
 
  int q,i,j,c=0,temp=Q;
  int S[N],T[Q];
 
  scanf("%d", &n);
 
  for(i=0 ; i<n ; i++){
    scanf("%d", &S[i]);
  }
 
   scanf("%d", &q);
 
  for(i=0 ; i<q ; i++){
    scanf("%d", &T[i]);
  }
 
  for(i=0 ; i<q ; i++){
    c+=binarySearch(S,T[i]);
  }
 
  printf("%d\n",c);
 
  return 0;
}
 
int binarySearch(int *A, int key){
 
  int c=0,left=0,right,mid;
 
  right=n;
 
  while(left<right){
    mid=(left+right)/2;
 
    if(key==A[mid]) {
      c++;
      break;
    }
    if(key>A[mid]) left=mid+1;
    else if (key<A[mid]) right = mid;
  }
 
  return c;
}

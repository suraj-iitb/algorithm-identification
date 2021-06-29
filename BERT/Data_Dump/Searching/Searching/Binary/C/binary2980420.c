#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int binarySearch(int *S,int key,int n);

int main(){
  int i,n,q,c,cnt = 0,value;
  int S[MAX],T[MAX];
  
  scanf("%d",&n);
  if(n>=100001) exit(1);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  if(q>=50001) exit(2);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    value = binarySearch(S,T[i],n);
    if(value != -1){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  
  return 0;
}

int binarySearch(int *S,int key,int n){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right)/2;
    if(S[mid] == key){
      return mid;
    }
    else if(key < S[mid]){
      right = mid;
    }
    else left = mid + 1;
  }
   return -1;
}


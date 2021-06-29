#include <stdio.h>
int BinarySearch(int);
int n,S[100000];
int main(){
  int i,q,count=0;
  int judge;
  int T[50000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    judge=BinarySearch(T[i]);
  if(judge >= 0)
    count++;
  }
  printf("%d\n",count);
  
  return 0;
}

int BinarySearch(int key){
  int left=0;
  int right=n;
  int mid;
  
  while(left < right){
    mid = (left + right)/2; 
  if(S[mid] == key)
    return mid;
  else if(key < S[mid])
    right = mid;
  else
    left = mid + 1;
  }
  return -5;
}

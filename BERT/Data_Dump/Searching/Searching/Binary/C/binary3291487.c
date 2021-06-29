#include<stdio.h>
int binarySearch(int*,int,int);

int main(){
  int n,q;
  int i=0;
  int count=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  int T[q];
  for(i=0;i < q;i++){
    scanf("%d",&T[i]);
    if(binarySearch(S,T[i],n) != -1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int*s,int k,int n){
  int left=0,right=n,mid;
  while(left<right){
    mid = (left+right)/2;
    if(s[mid]==k) return mid;
    else if(k<s[mid]) right = mid;
    else left = mid + 1;
  }
  return -1;
}


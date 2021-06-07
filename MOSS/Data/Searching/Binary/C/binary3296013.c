#include<stdio.h>


int binarySearch(int *,int,int);
int main(){
  int n,S[100000],q,T[50000],i,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    count+=binarySearch(S,T[i],n);
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int *S,int key,int right){
  int left,mid;
  left=0;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key)return 1;
    else if(key<S[mid])right=mid;
    else left=mid+1;
    }
    return 0;
}


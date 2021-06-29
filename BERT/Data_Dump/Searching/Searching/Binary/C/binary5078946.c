#include<stdio.h>

#define N 100000
#define Q 50000
#define FOUND 1
#define NOT_FOUND 0

int binalySearch(int,int);

int S[N],T[Q];

int main(){
  int i,n,q,k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  for(i=0;i<q;i++)
    k+=binalySearch(i,n);

  printf("%d\n",k);
  return 0;
}

int binalySearch(int i,int n){
  int left=0,right=n,mid,key;
  key=T[i];
  while(left<right){
    mid = (left+right)/2;
    if(S[mid]==key)return FOUND;
    else if(key<S[mid])right=mid;
    else left = mid+1;
  }
  return NOT_FOUND;
}


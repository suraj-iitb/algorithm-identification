#include<stdio.h>
#define N 100000
#define Q 50000

int binary(int n,int A[],int key){
  int left,right,mid;

  left=0;

  right=n;

  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key)return 1;
    else if(key<A[mid]) right=mid;
    else left=mid+1;
  }

  return 0;
}

int main(){

  int i,n,q,key,S[N],T[Q],cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    if(binary(n,S,T[i])==1)cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}


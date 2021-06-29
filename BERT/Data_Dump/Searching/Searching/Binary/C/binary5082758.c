#include<stdio.h>

#define W 100000
#define Q 50000
#define F 1
#define N 0

int bs(int,int);

int A[W],B[Q];

int bs(int i,int n){
  int left=0,right=n,mid,key;
  key=B[i];
  while(left<right){
    mid = (left+right)/2;
    if(A[mid]==key)return F;
    else if(key<A[mid])right=mid;
    else left = mid+1;
  }
  return N;
}

int main(){
  int i,n,q,k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&B[i]);
  for(i=0;i<q;i++)
    k+=bs(i,n);

  printf("%d\n",k);
  return 0;
}




#include<stdio.h>
int search(int A[],int n,int key){
  int l=0;
  int r=n;
  int mid;
  while(l<r){
    mid=(l+r)/2;
    if(key==A[mid])return 1;
    if(key>A[mid])l=mid+1;
    else if(key<A[mid])r=mid;
  }
  return 0;
}

int main(){
  int A[1000000],n;
  int i,q,k,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(search(A,n,k))sum++;
  }
  printf("%d\n",sum);
  return 0;
}

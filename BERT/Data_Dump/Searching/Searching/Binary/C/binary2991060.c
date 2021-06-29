#include<stdio.h>
int bisearch(int);
int A[10000000],n;
int main(){
  int i,q,judge,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&judge);
    if(bisearch(judge)) count++;
  }
  printf("%d\n",count);
  return 0;
}

int bisearch(int key){
  int l=0,r=n,mid;
  while(l<r){
    mid=(l+r)/2;
    if(key==A[mid]) return 1;
    if(key>A[mid]) l=mid+1;
    else if(key<A[mid]) r=mid;
  }
  return 0;
}




#include<stdio.h>

#define N 100000
#define Q 50000

int Bsearch(int,int);

int S[N],T[Q];

int main(){
  int i,n,q,k=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  for(i=0;i<q;i++)
    k+=Bsearch(i,n);

  printf("%d\n",k);
  return 0;
}

int Bsearch(int i,int n){
  int l=0,r=n,mid,key;
  key=T[i];
  while(l<r){
    mid = (l+r)/2;
    if(S[mid]==key)return 1;
    else if(key<S[mid])r=mid;
    else l = mid+1;
  }
  return 0;
}

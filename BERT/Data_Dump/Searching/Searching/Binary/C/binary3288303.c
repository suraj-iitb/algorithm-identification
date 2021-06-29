#include<stdio.h>

int BinarySearch(int ,int ,int *);

int main(){
  int n,q;
  scanf("%d",&n);
  int i,S[n];
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  int cnt=0;
  for(i=0;i<q;i++)cnt+=BinarySearch(n,T[i],&S[0]);
  printf("%d\n",cnt);
  return 0;
}

int BinarySearch(int n,int key,int *x){
  int left=0,right=n,mid;
  while(right>left){
    mid=(left+right)/2;
    if(key==x[mid])return 1;
    if(key>x[mid])left=mid+1;
    else if(key<x[mid])right=mid;
  }
  return 0;
}



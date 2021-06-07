#include<stdio.h>
#include<stdlib.h>
#define M 1000000
int lub(int l,int r,int n,int *d){
  int m=(l+r)/2;
  if(l==r)return m;
  return n<=d[m]?lub(l,m,n,d):lub(m+1,r,n,d);
}
int main(){
  int n,m,d[100010],c=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  scanf("%d",&m);
  while(m--){
    scanf("%d",&i);
    if(d[lub(0,n-1,i,d)]==i)c++;
  }
  printf("%d\n",c);
  return 0;
}

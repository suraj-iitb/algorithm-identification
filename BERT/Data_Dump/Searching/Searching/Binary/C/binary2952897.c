#include <stdio.h>
int binary(int,int,int *);
int main(){
  int i,n,s[100000],cnt=0,t[50000],q;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    cnt+=binary(n,t[i],s);
  }
  printf("%d\n",cnt);
  return 0;
}
int binary(int n,int t,int *s){
  int mid,left,right;
  right=n;
  left=0;
  while(right>left){
    mid=(right+left)/2;
    if(s[mid]==t)return 1;
    else if(s[mid]>t)right=mid;
    else if(s[mid]<t)left=mid+1;
  }
  return 0;
}

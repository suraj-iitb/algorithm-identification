#include <stdio.h>
int binary_search(int *s,int key,int n){
  int l,r;
  int m;
  l=0;
  r=n-1;
  while(l<=r){
    m=(l+r)/2;
    if(key==s[m]) return 1; 
    if(key<s[m])r=m-1;
    else l=m+1;
  }
    return 0;
}
int main(){
  int i,j;
  int n=15;
  int s[100000];
  int q;
  int count=0;
  int t;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&t);
    count=count+binary_search(s,t,n);
  }
  printf("%d\n",count);
  return 0;
}

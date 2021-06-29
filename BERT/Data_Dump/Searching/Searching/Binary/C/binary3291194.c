#include <stdio.h>

#define N 100000

int main(){
  int n,q,s[N],t[N],r,l,m,ans=0,i,j;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0; j<q; j++) scanf("%d",&t[j]);
  for(j=0; j<q; j++){
    l=0;
    r=n;
    while(l<r){
      m=(l+r)/2;
      if(s[m]==t[j]){
	ans++;
	break;
      }else if(s[m]<t[j]){
	l=m+1;
      }else{
	r=m;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}


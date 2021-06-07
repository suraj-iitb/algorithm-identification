#include <stdio.h>

#define N 10000

int main(){
  int n,q,s[N],t[N],i,j,ans=0;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0; j<q; j++) scanf("%d",&t[j]);
  for(j=0; j<q; j++){
    for(i=0; i<n; i++){
      if(s[i]==t[j]){
	ans++;
	break;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}


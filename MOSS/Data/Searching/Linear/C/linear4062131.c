#include<stdio.h>

int main(){
  int n,q,s[10001],t,i,j = 0,ans = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",s + i);

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t);
    s[n] = t;
    while(s[j] != t) j++;
    if(j != n) ans += 1;
    j = 0;
  }

  printf("%d\n",ans);

  return 0;
}


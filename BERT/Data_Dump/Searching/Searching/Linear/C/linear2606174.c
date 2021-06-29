#include<stdio.h>

int main() {
  int s[10000],t[500],i,j,n,q,ans=0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for (i = 0; i < q; i++)
    scanf("%d",&t[i]);
  for (i = 0; i < q; i++) {
    for (j = 0; j < n; j++){
      if(t[i]==s[j]){
        ans++;
        break;
   }
   }
}
  printf("%d\n",ans);
  return 0;
}

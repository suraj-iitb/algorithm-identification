#include <stdio.h>

int main()
{
  int n,q,i,j,k,s[10005],t[505],cnt=0,key;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0;j<q;j++) scanf("%d",&t[j]);

  for(i=0;i<q;i++){
    key=t[i];
    for(j=0;j<n;j++){
      if(key==s[j]){
        //printf("%d %d %d %d %d\n",key,t[j],cnt,i,j);
        cnt++;
        break;
      }
    }
  }
  printf("%d\n",cnt);

  return 0;
}

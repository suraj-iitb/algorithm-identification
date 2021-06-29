#include <stdio.h>

int main(){
  int n,s[10001],q,t[500],count=0,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);
  for(i=0;i<q;i++){
    s[n]=t[i];
    j=0;
    while(s[j]!=t[i]) j++;
    if(j<n) count++;
  }
  printf("%d\n",count);
  return 0;
}
  
      


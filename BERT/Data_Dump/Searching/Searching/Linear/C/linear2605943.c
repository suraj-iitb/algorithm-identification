#include <stdio.h>

int main(void)
{
 int i,j,n,S[10000],q,T[500],ans=0;

 scanf("%d",&n);

 for(i=0;i<n;i++){
  scanf("%d",&S[i]);
 }

 scanf("%d",&q);

 for(i=0;i<q;i++){
  scanf("%d",&T[i]);
 }

 for(i=0;i<q;i++){
  j=0;
  while(T[i]!=S[j]){
   j++;
   if(j==n) break;
  }
  if(j!=n) ans++;
 }

 printf("%d\n",ans);

 return 0;
}  

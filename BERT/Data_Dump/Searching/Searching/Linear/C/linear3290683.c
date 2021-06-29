#include<stdio.h>

int main()
{
  int n,q,S[10000],T[500],i,j,c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    S[n]=T[i];
    j=0;
    while(S[j]!=T[i]){
      j++;
    }
    if(j!=n) c++;
  }
  printf("%d\n",c);
  return 0;
}
      


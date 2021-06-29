#include<stdio.h>
int main()
{
  int j,i,n,q,C=0;
  int S[10000],T[500],c[500];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){
      if(S[i]==T[j]){
	C++;
        T[j]=-1;
      }
    }
  }
  printf("%d\n",C);
  return 0;
}

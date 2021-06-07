#include <stdio.h>

int main()
{
  int n,q,C=0,i,j;
  int S[10000],T[500];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
    j=0;
    while(j<n){
      if(S[j]==T[i]){
        C++;
        break;
      }
      j++;
        }
  }

  printf("%d\n",C);

  return 0;
}

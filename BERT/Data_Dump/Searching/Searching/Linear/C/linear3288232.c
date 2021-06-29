#include <stdio.h>

int main()
{
  int n,q,i,j,C=0;
  
  scanf("%d",&n);

  int S[n];

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  int Q[q];

  for(i=0;i<q;i++){
    scanf("%d",&Q[i]);
    for(j=0;j<n;j++){
      if(S[j]==Q[i]){
          C++;
          break;
      }
    }
  }
  
   printf("%d\n",C);


  return 0;
}


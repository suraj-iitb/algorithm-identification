#include <stdio.h>
int main(){
  int i,j,n,q,c=0;

  scanf("%d",&n);

  int S[n+1];
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);

    j=0;
    S[n]=T[i];

    while(S[j]!=T[i]) j++;

    if(j!=n) c++;
  }

  printf("%d\n",c);

  return 0;
}

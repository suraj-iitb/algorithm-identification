#include <stdio.h>

int main()
{
  int n,q,i,l,m,r,C=0;

  scanf("%d",&n);

  int S[n];

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  int T[q];

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    l=0;
    r=n;
    while(l<r){
      m=(l+r)/2;
      if(T[i]==S[m]){
	C++;
	break;
      }
      if(T[i]>S[m]) l=m+1;
      else if (T[i]<S[m]) r=m;
    }
  }

  printf("%d\n",C);

  return 0;
}

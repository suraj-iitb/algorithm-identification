#include <stdio.h>

int main()
{
  int n,q;
  int count=0,i,j,L,M,R;
  int S[100000],T[50000];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
    L = 0;
    R = n;
    while(L < R){
      M = (L + R) / 2;
      if(S[M] < T[i])
        L = M + 1;
      if(S[M] == T[i]){
        count++;
        break;
      }
      if(S[M] > T[i])
        R = M;
    }
  }
  printf("%d\n",count);

  return 0;
}

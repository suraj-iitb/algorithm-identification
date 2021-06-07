#include <stdio.h>
#include <stdlib.h>
#define N 100000
int main()
{
  int i,j,n,q,S[N],T[N],count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    scanf("%d",&T[i]);
  for(i = 0;i < q;i++){
    j = 0;
    while(S[j] != T[i])
    {      
      j++;      
      if(j == n - 1) break; 
    }
    if(S[j] == T[i]) count++;
    
     
  }

  printf("%d\n",count);
  return 0;
}
  


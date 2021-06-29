#include <stdio.h>

int main()
{
  int n,q,i,L,R,M,onaji=0;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++)scanf("%d",&S[i]);

  scanf("%d",&q);
  int T[n];
  for(i=0;i<q;i++)scanf("%d",&T[i]);

 

  for(i=0;i<q;i++)
    {
      L=0;
      R=n;
       if(T[i]<=S[n-1]&&T[i]>=S[0])
	 {
	   while(L<R)
	     {
	       M=(L+R)/2;
	       if(S[M]==T[i])
		 {
		   onaji++;
		   break;
		 }
	       else if(T[i]<S[M])R=M;
	       else L=M+1;
	     }
	 }
    }
  
  printf("%d\n",onaji);
  return 0;
}


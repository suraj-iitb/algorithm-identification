#include<stdio.h>
#include<stdlib.h>


int main()
{
  int *S,*T;
  int n,q,i,j,count=0;

  scanf("%d",&n);
  S=(int *)malloc((n+1)*sizeof(int));

  for(i=0;i<n;i++)
  {
    scanf("%d",&S[i]);
  }


  scanf("%d",&q);
  T=(int *)malloc(q*sizeof(int));

  for(i=0;i<q;i++)
  {
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++)
  {
    j=0;
    S[n]=T[i];
    while(S[j]!=T[i]) j++;
    if(j==n) continue;
    count++;
  }

  printf("%d\n",count);
  free(S);
  free(T);

  return 0;
}

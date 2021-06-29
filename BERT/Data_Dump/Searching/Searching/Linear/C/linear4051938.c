#include <stdio.h>

int main(){
  int n,q,k,S[10000],T[500],i,c=1,count=0;
  scanf("%d",&n);
  for(k=0;k<n;k++){
    scanf("%d",&S[k]);
  }
  scanf("%d",&q);
  for(k=0;k<q;k++){
    scanf("%d",&T[k]);
  }

  for(k=0;k<q;k++)
    {
      i=0;
      S[n]=T[k];
      while(S[i]!=T[k])
	{
	  i++;
	  if(i==n){c=0;break;}
	}
      if(c==1)count++;
      c=1;
    }

  printf("%d\n",count);
  return 0;
}


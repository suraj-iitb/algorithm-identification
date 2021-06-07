#include<stdio.h>
#define N 101
int sum[N][N],num[N],tum[N];
int n,i;

void rum(int xu){
  int a;
  tum[xu]=++i;
  for(a=0;a<n;a++)
    {
      if(sum[xu][a] && tum[a]==0)rum(a);
    }
  num[xu]=++i;
}

      
int main()
{
  int a,b,c,d,e;
  scanf("%d",&n);
  for(a=0;a<n;a++)
    {
      tum[a]=0;
      num[a]=0;
      for(b=0;b<n;b++)sum[a][b]=0;
    }
  for(a=0;a<n;a++)
    {
      scanf("%d",&c);
      scanf("%d",&d);
      for(b=0;b<d;b++)
	{
	  scanf("%d",&e);
	  sum[c-1][e-1]=1;
	}
    }
  i=0;
  for(a=0;a<n;a++)
    {
      if(tum[a]==0)
	rum(a);
    }
  for(a=0;a<n;a++)printf("%d %d %d\n",a+1,tum[a],num[a]);

  return 0;
}

	
  
  
  
			    			    
	
	
  


#include<stdio.h>

int mid(int, int);
int m;

int main()
{
  int i=0,l=0,r;
  int S[10000000],T,n,q,count=0;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    {
      scanf("%d",&S[i]);
    }
  r=n;
  m=mid(l,r);
  
  scanf("%d",&q);
  for(i=0; i<q; i++)
    {
      scanf("%d",&T);
      
      while(l<r)
	{
	  if(S[m]==T)
	    {
	      count++;
	      
	      r=n;
	      l=0;
	      m=mid(l, r);
	     
	      
	      break;
	    }
	  else if(S[m]>T)
	    {
	  
	      r=m;
	      m=mid(l, r);
	      
	    }
	  else if(S[m]<T)
	    {
	      l=m+1;
	      m=mid(l, r);
	      
	    }
	  else if(l==m)
	    {
	      
	      r=n;
	      l=0;
	      m=mid(l, r);
	      break;
	    } 
	  
	} 
	

      r=n;
      l=0;
      m=mid(l,r);


	   
    }
  printf("%d\n",count);
  return 0;
}
  
int mid(int l, int r)
{

  m=(l+r)/2;
  return m;
}


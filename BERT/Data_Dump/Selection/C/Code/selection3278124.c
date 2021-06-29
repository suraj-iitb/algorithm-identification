#include<stdio.h>

int main()
{
  int i,j,s,count=0,a[100],n,temp,minj;

  scanf("%d",&n);
  for(s=0;s<n;s++)
    {
      scanf("%d",&a[s]);
    }

  
  for(i=0;i<=n-1;i++)
    {
      minj=i;
      for(j=i;j<=n-1;j++)
	{
	  if(a[j]<a[minj])
	    {
	      minj=j;
	    }
	}
	      temp=a[i];
	      a[i]=a[minj];
	      a[minj]=temp;
	      if(i!=minj) count++;
	    
	
    }

  for(i=0;i<n;i++)
    {
      if(i>0) printf(" ");
      printf("%d",a[i]);
    }
  printf("\n");
  printf("%d\n",count);

  return 0;
}


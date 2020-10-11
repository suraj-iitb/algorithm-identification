#include<stdio.h>
#define N 100


int main()
{
  int B[N],i,j,n,cnt=0,minj,temp;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&B[i]);
    }

  
   for(i=0;i<n;i++)
    {
      minj = i;
      for(j=i;j<n;j++)
	{
	  if(B[j] < B[minj])
	    {
	      minj = j;

	      temp = B[i];
	      
	      
	    }
	}
      if(minj != i)
	{
	   B[i] = B[minj];
	   B[minj] = temp;
           cnt++;
	}
    }

   for(i=0;i<n;i++)
     {
       printf("%d",B[i]);
       if(i!=n-1)printf(" ");
     }
   printf("\n%d\n",cnt);
  
  return 0;
}



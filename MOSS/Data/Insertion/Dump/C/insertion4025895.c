#include<stdio.h>


int main()
{
  int N,a,b,c;
  int sum[1000];
    
   
    scanf("%d",&N);
    
    for(a=0;a<N;a++)
    {
      scanf("%d",&sum[a]);
    }
    for(a=0;a<N;a++){
      b=sum[a];
      c=a-1;
      while(c>=0 && sum[c]>b)
	{
	  sum[c+1]=sum[c];
	  c--;
	}
      sum[c+1]=b;
      for(c=0;c<N-1;c++)
	{
	  
	  printf("%d ",sum[c]);
	 
	}
      printf("%d",sum[c]);
      printf("\n");
    }
    
   
    
    return 0;
}

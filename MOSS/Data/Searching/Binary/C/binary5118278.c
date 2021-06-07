#include<stdio.h>

int main( void ) 
{
    int i;
    int x[100001];
	int y[100001];
    int count;
    int low;
	int high;
	int mid;
	int n;
	int p;
       
    scanf("%d",&n);
	
    for(i=0;i<n;i++)
	{
        scanf("%d",&x[i]);
    }
   
    scanf("%d",&p);
	
    for(i=0;i<p;i++)
	{
        scanf("%d",&y[i]);
    }
    
    count=0;
	
    for(i=0;i<p;i++) 
	{
		low=0;
		high=n;
		while(low<=high)
		{
			mid=(low+high)/2; 
            if(y[i]==x[mid]) 
			{
                count++;
                break;
            } 
			else if(y[i]<x[mid]) 
			{
            	high=mid-1;
            }
			else
			{
            	low=mid+1;
            }
        }
    }
    if(count)
	{
        printf("%d\n",count);
    } 
	else
	{
        printf("0\n");
    }
   
    return 0;
	
}

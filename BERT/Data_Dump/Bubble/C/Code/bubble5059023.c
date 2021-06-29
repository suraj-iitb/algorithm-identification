#include <stdio.h>

int main(void)
{
	int N,i,j,change,*array,flag,count=0;
	scanf("%d",&N);
	array=(int *)malloc(N * sizeof(int));
	for(i=0;i<N;i++)
    {
    	scanf("%d",&array[i]);
    }
    
    flag=1;
    i=0;
    while(flag)
    {
    	flag=0;
    	for(j=N-1;j>=i+1;j--)
    	{
    		if(array[j] < array[j-1])
    		{
    			change=array[j];
    			array[j] = array[j-1];
    			array[j-1] = change;
    			count++;
    			flag=1;
    		}
    		
    	}
    	i++;
    }
    for(i=0;i<N-1;i++)
    {
    	printf("%d ",array[i]);
    }
    printf("%d",array[i]);
    printf("\n");
    printf("%d\n",count);
    return 0;
}

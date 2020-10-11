#include<stdio.h>

int A[10000];
int main( void ) 
{
  
    int mini,n,count=0;
    scanf( "%d", &n );
     
    int i, j;

    for( i=0; i<n; i++ ) 
	{
       scanf( "%d", &A[i] );
    }
    for( i=0;i<n;i++) 
    {    
		mini = i;
        for(j=i;j<n;j++)
        {
            if(A[mini]>A[j])
            {
				mini = j;
            }
        }
		if(i!=mini)
			{
				int temp = A[mini];
				A[mini] = A[i];
				A[i] = temp;
				count++;
			}
    }
	for(i = 0 ; i < n-1 ; i++)printf("%d ",A[i]);
 
	printf("%d\n",A[i]);
	printf("%d\n",count);
    return 0;
	
}

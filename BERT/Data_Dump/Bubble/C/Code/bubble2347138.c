#include<stdio.h>



int A[10000];
int main( void ) 
{
  
    int n,count=0;
    scanf( "%d", &n );
     
    int i, j;

    for( i=0; i<n; i++ ) 
	{
        scanf( "%d", &A[i] );
    }
    for( i=n; i>0; i-- ) 
	{    
        for(j=0;j<i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1]=temp;
				count++;
			}
		}
	}
	printf("%d",A[0]);
    for(i=1;i<n;i++) printf(" %d",A[i]);
    printf("\n");
    printf("%d\n",count);

    return 0;
	
}

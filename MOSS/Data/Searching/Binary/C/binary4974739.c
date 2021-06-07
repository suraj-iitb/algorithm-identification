#include<stdio.h>

int binarySearch(int A[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;
    
	while (left < right)
    {
        mid = (left + right) / 2;
        if( A[mid] == key)
            return 1;
        else if( key < A[mid])
            right = mid;
        else
    		left = mid + 1;
     }
     
    return -1;
} 
    
    
int main(void)
{
	int n,q,i,c=0;
	
	scanf("%d",&n);
	
	int S[n];
	for(i=0; i<n; i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	int T[q];
	for(i=0; i<q; i++)
	{
		scanf("%d",&T[i]);
	}
	
	for(i=0; i<q; i++)
	{
		if(binarySearch(S,n,T[i])==1)
			c++;
	}
	
	printf("%d\n",c);
	
	return 0;
}

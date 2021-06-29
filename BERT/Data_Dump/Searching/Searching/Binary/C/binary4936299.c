#include<stdio.h>

int binarySearch(int T[],int S[],int n,int j)
{	
	int left = 0;
    int right = n;
	int mid;
	
	while(left < right)
	{
        mid = (left + right) / 2;
		if(S[mid] == T[j])
		{
            return mid;
		}
		else if(T[j] < S[mid])
		{    
	 		right = mid;
		}
		else{left = mid + 1;}
	}
	
    return -1;
}

int main(void)
{
	int n,S[200000],q,T[200000],C=0,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
		
		if(binarySearch(T,S,n,j)!= -1){C++;}
	}
	
	printf("%d\n",C);
	
	return 0;
}

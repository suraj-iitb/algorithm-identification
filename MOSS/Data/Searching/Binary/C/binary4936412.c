#include<stdio.h>

#define MAX_s 100000
#define MAX_t 50000

int binarySearch(int A[],int key,int n)
{
	int left = 0;
	int right = n;
	int mid;
	
	while (left < right)
	{
        mid = (left + right) / 2;
		if (A[mid] == key){
           return mid;
		}else if (key < A[mid]){
            right = mid;
		}else{
            left = mid + 1;
		}
	}
    return 0;
}

int main(void)
{
	int i,j,k,n,q;
	int c=0;
	int S[MAX_s];
	int T[MAX_t];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(j=0;j<q;j++)
	{
		scanf("%d",&T[j]);
	}
	
	for(k=0;k<q;k++)
	{
		if(binarySearch(S,T[k],n)){
			c++;
		}
	}
	
	printf("%d\n",c);
	
	return 0;
}

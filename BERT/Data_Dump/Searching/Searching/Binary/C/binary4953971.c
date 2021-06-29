#include <stdio.h>
int linearSearch(int S[], int n, int key);

int main(void)
{
    int i, sum=0, n, q;
    
    scanf("%d", &n);
    
    int S[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &S[i]);
    }
    
    scanf("%d", &q);
    
    int T[q];
    for(i=0; i<q; i++)
    {
        scanf("%d", &T[i]);
        if(binarySearch(S, n, T[i])==1) sum++;
    }
    
    printf("%d\n", sum);
    
    return 0;
}

int binarySearch(int S[], int n, int key)
{
	int left=0, right=n, mid;
	while(left<right)
	{
	    mid=(left+right)/2;
	    if(S[mid]==key) return 1;
	    else if(S[mid]>key) right=mid;
	    else left=mid+1;
	}
	
	return 0;
}

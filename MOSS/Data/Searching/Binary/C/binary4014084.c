#include<stdio.h>

int binarySearch(int A[],int n,int key)
{
	int left=0;
	int right=n;
	int mid=0;
	while(left<right)
	{
		mid = (left+right)/2;
		if(A[mid]==key) return 1;
		else if(key < A[mid]) right = mid;
		else left=mid+1;
	}
	return 0;
}

int main(void)
{
	int n=0,q=0,i=0,key=0,count=0;
	scanf("%d", &n);
	int S[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	int T[q];
	for(i=0; i<q; i++){
		scanf("%d", &key);
		count = count + binarySearch(S, n, key);
	}
	printf("%d\n",count);
	return 0;
}



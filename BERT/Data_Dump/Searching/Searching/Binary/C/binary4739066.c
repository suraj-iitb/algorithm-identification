#include <stdio.h>

int A[1000000],n;

int binarySearch(int key)
{
	int left=0;int right=n;
	int mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(key==A[mid]) return 1;
		if(key>A[mid]) left=mid+1;
		else if(key<A[mid]) right=mid;
	}
	return 0;
}
 
 int main()
 {
 	int i,key,m,sum=0;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	scanf("%d",&A[i]);
 	scanf("%d",&m);
 	for(i=0;i<m;i++)
 	{
 		scanf("%d",&key);
 		if(binarySearch(key)) sum++;
	 }
	 printf("%d\n",sum);
	 return 0;
 }

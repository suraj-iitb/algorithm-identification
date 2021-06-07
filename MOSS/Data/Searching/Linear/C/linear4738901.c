#include <stdio.h>

int search(int A[], int n, int key)
{
	int i=0;
	A[n]=key;
	while(A[i]!=key)
	i++;
	return i!=n;
 } 
 
 int main()
 {
 	int n,m,key,A[10001],i,sum=0;
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	scanf("%d",&A[i]);
 	scanf("%d",&m);
 	for(i=0;i<m;i++)
 	{
 		scanf("%d",&key);
 		if(search(A,n,key)) sum++;
	 }
	 printf("%d\n",sum);
	 return 0;
 }

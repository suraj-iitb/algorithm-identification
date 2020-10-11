#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 2000010
#define Ai 10000
int A[MAX],B[MAX],C[Ai]={0};
int n;
void countingsort()
{
	int i;
	for(i=1;i<=n;i++)
		C[A[i]]++;
	for(i=1;i<=Ai;i++)
		C[i]=C[i]+C[i-1];
	for(i=n;i>=1;i--)
	{
		B[C[A[i]]]=A[i];
		C[A[i]]--;
	}
	return;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	countingsort();
	for(i=1;i<=n-1;i++)
		printf("%d ",B[i]);
	printf("%d\n",B[n]);
	return 0;
}

#include<stdio.h>

int linearsearch(int A[], int n, int key)
{
	int i=0;
	
	A[n] = key;
	
	while(A[i] != key){

			i++;
	}
	
	if(i==n)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int main(void)
{

int n, q, count;



count = 0;

scanf("%d", &n);

int S[n];

for(int i=0; i<n; i++)
{
	scanf("%d", &S[i]);
}

scanf("%d", &q);

int T[q];
	
for(int i=0; i<q; i++)
{
	scanf("%d", &T[i]);
}

for(int i=0; i<q; i++)
{
	if(linearsearch(S,n,T[i])==1)
	{
		count++;
	}
}
	
	printf("%d\n", count);


return 0;

}

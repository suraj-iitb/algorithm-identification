#include<stdio.h>

int main(void)
{

int n, i, j, count, temp, min;
count = 0;
	
scanf("%d", &n);

int A[n];

for(i=0; i<n ; i++)
{
	scanf("%d", &A[i]);
}
		
for(i = 0; i <n; i++)
{
	min = i;
			
	for(j=i; j<n ; j++)
	{
			
		if(A[j] < A[min])
		{
			min = j;
			
		}
		
		
	}
	
	temp = A[i];
	A[i] = A[min];
	A[min] = temp;
	
	if(A[i] != A[min])
	{
		count++;
	}
	
}
		
for(i=0; i<n-1; i++)
{
	printf("%d ", A[i]);

}
	
printf("%d\n", A[n-1]);
	
printf("%d\n", count);
	
return 0;
	
	
}

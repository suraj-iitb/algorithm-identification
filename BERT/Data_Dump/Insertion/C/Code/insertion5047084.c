#include <stdio.h>

int main()
{
	int N;
	int j,i,v,s;
	scanf("%d",&N);
	int A[1000];
	
	for(i=0;i<N;i++)
	{
	scanf("%d",&A[i]);	
	}
	
	
	for(i=0;i<N-1;i++)
	{
	printf("%d ",A[i]);
	}
	
	printf("%d\n",A[i]);
	
	for(i=1;i<=N-1;i++)
	{
     v = A[i];
     j = i - 1;
     while(j >= 0 && A[j] > v)
	 {
      A[j+1] = A[j];
      j--;
	 }
      A[j+1] = v;
	 for(s=0;s<N-1;s++)
	 printf("%d ",A[s]);
	 printf("%d\n",A[s]);
	}
	return 0;
}

#include<stdio.h>
void insertionSort(int A[], int N)
{
    int j,i,v;
    for(i=1; i<N; i++)
    {
        v=A[i];
        j=i-1;
        while(j>=0 && A[j] > v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    	
    	int k;
    	for(k=0; k<N; k++)
    	{
			if(k!=0)printf(" ");
        	printf("%d", A[k]);
    	}
		printf("\n");
    }

}
int main(void)
{
    int N;
    scanf("%d", &N);
    int A[N];
	int i;
	for(i=0; i<N; i++)
	scanf("%d", &A[i]);
    int k;
    for(k=0; k<N; k++)
    {
		if(k>0)printf(" ");
    	printf("%d", A[k]);
    }
	printf("\n");
    insertionSort(A, N);

    return 0;
}

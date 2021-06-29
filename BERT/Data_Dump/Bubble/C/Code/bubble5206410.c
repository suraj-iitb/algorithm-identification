#include<stdio.h>


int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    int s;
    for (s=0; s<N; s++){
        scanf("%d", &A[s]);
    }
    int c =0;
    int i, j;
	for(i=0;i<N-1;i++)
		for(j=N-1;j>i;j--)
			if(A[j]<A[j-1])
			{
				c++;
				A[j]^=A[j-1]^=A[j]^=A[j-1];
			}
    for(i = 0; i < N; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", c);
	return 0;
}


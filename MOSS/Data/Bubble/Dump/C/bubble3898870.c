#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int A[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);	
	}
	
	int count=0;
	
	 for(int i=0;i<N-1;i++)
        for(int j=0;j<N-i-1;j++)
        if(A[j]>A[j+1])
    {
        int t;
        t=A[j];
        A[j]=A[j+1];
        A[j+1]=t;
        count++;
    }
	
	for(int k=0;k<N;k++)
        {
            //cout<<A[k];
            printf("%d",A[k]);
            if(k!=N-1)
                printf(" ");
        }
    printf("\n");
    printf("%d\n",count);
    return 0;
}

#include<stdio.h>

int main(void){
	int N;
	scanf("%d",&N);
	int i,A[N+1];
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	int j,k,minj,t,count;
	count=0;
	for(j=0;j<N;j++)
	{
		minj=j;
		for(k=j;k<N;k++)
		{
			if(A[k]<A[minj]){
			minj=k;
			}
		}
		t=A[j];
		A[j]=A[minj];
		A[minj]=t;
		if(A[j]!=A[minj])
		{
		count++;
		}
	}
	
	for(int k=0;k<N;k++)
        {
            //cout<<A[k];
            printf("%d",A[k]);
        	if(k!=N-1){
                printf(" ");
        	}
        }
    printf("\n");
    printf("%d\n",count);
	return 0;
}

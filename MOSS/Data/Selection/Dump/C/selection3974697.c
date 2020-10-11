#include <stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	int i,j,min=0,tmp=0,k=0;
	int A[N];
	
	for(i=0;i<N;i++)  //配列読み込み
	{
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;i++){		//選択ソート
		min=i;
		for(j=i;j<N;j++){		
			if(A[j]<A[min]){
				min=j;
			}
		}
		
		if(i!=min){
			tmp=A[i];
			A[i]=A[min];
			A[min]=tmp;
			k++;
			}
		
		}
	   
	
	
	
	for(i=0;i<N;i++)
	{
		printf("%d",A[i]);
		if(i<N-1)
		{
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",k);
	return 0;

}

	

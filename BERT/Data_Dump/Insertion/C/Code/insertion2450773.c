#include<stdio.h>

void sort(int A[],int N);
void trace(int A[],int N);

void trace(int A[],int N)
{
	int i;
	for(i=0;i<N;i++){
		if(i>0){ printf(" ");
		
		}
		printf("%d",A[i]);
	}
	printf("\n");
}

void sort(int A[],int N)
{
	int i,j,v;
	for(i=1;i<N;i++){
		v=A[i];//??????A[i]???????????£
		j=i-1;
		for(j=i-1;j>=0&&A[j]>v;j--){
			A[j+1]=A[j];
		}
	A[j+1]=v;
	trace(A,N);
		
	}


}

int main()
{
	int N,A[114514];
	int i,k;
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d",&A[i]);
	
	
	trace(A,N);
	sort(A,N);

	


	return 0;
}

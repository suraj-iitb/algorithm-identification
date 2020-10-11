#include<stdio.h>

int bubbleSort(int A[], int N){
	int flag=1,tmp,count=0;
	while(flag){
		flag = 0;
		for(int i=N-1; i>0; --i){
			if(A[i] < A[i-1]){
				tmp=A[i];
				A[i]=A[i-1];
				A[i-1]=tmp;
				
				flag = 1;
				count++;
				}
		}
		
	}
	for(int i=0; i<N; ++i){
		if(i>0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
	printf("%d\n",count);
	return 0;
}





int main(){
	int N;
	scanf("%d",&N);
	
	int A[N];
	for(int i=0; i<N; ++i){
		A[i] = 0;
	}
	
	for(int i=0; i<N; ++i){
		int m;
		scanf("%d",&m);
		A[i] = m;
	}
	
	bubbleSort(A,N);


 return 0;
}

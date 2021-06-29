#include<stdio.h>

void swap(int* a,int* b);
void PRINT(int* A, int N);

int main(void){
	int N, i, j, flag=1,n=0;
	
	scanf("%d",&N);
	int bubbleSort[N];
	for(i=0;i<N;i++){
		scanf("%d", &bubbleSort[i]);
	}
	
	i=0;
	while(flag){
		flag=0;
		for(j=N-1;j>i;j--){
			if(bubbleSort[j] < bubbleSort[j-1]){
				swap(&bubbleSort[j],&bubbleSort[j-1]);
				n++;
				flag=1;
			}
		}
		i++;
	}
	PRINT(bubbleSort, N);
	printf("%d\n",n);
	
	return 0;
}

void swap(int* a,int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void PRINT(int* A, int N){
	int i;
	printf("%d",A[0]);
	for(i=1;i<N;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
}

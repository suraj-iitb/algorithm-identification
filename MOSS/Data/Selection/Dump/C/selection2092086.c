#include<stdio.h>

void swap(int* a,int* b);
void PRINT(int* A, int N);

int main(void){
	int N, i, j, minj,n=0;
	int flag=1, n1=0, n2=0;
	
	scanf("%d",&N);
	int selectionSort[N];
	for(i=0;i<N;i++){
		scanf("%d", &selectionSort[i]);
	}
	
	for(i=0;i<N;i++){
		minj = i;
		for(j=i;j<N;j++){
			if(selectionSort[j] < selectionSort[minj]){
				minj = j;
			}
		}
		if(i!=minj){
			swap(&selectionSort[i],&selectionSort[minj]);
			n++;
		}
	}
	
	PRINT(selectionSort,N);
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

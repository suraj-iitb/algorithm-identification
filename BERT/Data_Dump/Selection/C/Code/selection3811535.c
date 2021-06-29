#include<stdio.h>
/*ALDS1_2_B*/

void SelectionSort(int array[],int N)
{
	int i,j;
	int minj;
	int temp;
	int count=0;
	
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(array[j]<array[minj]){
				minj=j;
			}
		}
		if(minj != i){
			temp=array[i];
			array[i]=array[minj];
			array[minj]=temp;
			count++;
		}
	}
	
	for(i=0;i<N;i++){
		printf("%d",array[i]);
		if(i!=N-1)printf(" ");
		else printf("\n");
	}
	printf("%d\n",count);
}

int main(void)
{
	int array[100]={0};
	int N;
	int i;
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&array[i]);
	}
	
	SelectionSort(array,N);
}

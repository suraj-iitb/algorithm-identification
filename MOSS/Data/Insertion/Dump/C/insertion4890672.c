#include<stdio.h>

void arrayShow(int array[],int n);
void insertionSort(int array[],int n);

int main(){

	int array[1000];
	int i,n;
	
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&array[i]);
	}
	insertionSort(array,n);

	return 0;
}

void arrayShow(int array[],int n){

	int i= 0;
	for(;i < n - 1 ;i++){
		printf("%d ",array[i]);
	}
	printf("%d\n",array[i]);
}

void insertionSort(int array[],int n){


	int i;
	int v;
	int j;
	for(i = 0;i < n;i++){
		v = array[i];
		j = i - 1;
		while((j >= 0) && array[j] > v){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = v;
		arrayShow(array,n);
	}

}

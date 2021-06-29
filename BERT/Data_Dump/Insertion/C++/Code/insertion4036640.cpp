#include<stdio.h>

void swap(int* x,int* y){
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;
}

void insert_sort(int array[1000], int array_size){
	int j=0;
	for(int i=0; i<array_size; i++){
		j=i;
		while((j>0)&&(array[j-1]>array[j])){
			swap(&array[j-1],&array[j]);
			j--;
		}
		for(int j=0; j<array_size; j++){
			if(!(j==array_size-1)){
				printf("%d ",array[j]);
			}else{
				printf("%d\n",array[j]);
			}
		}
	}
}

int main(){
	int array_size=0;
	scanf("%d",&array_size);
	int array[1000]={};
	for(int i=0; i<array_size; i++){
		scanf("%d",&array[i]);
	}
	insert_sort(array,array_size);
	return 0;
}


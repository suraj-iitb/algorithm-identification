#include<stdio.h>

void swap(int *x,int *y){
	int tmp=0;

	tmp=*x;
	*x=*y;
	*y=tmp;
}

void bubble_sort(int array[],int array_size, int *count){
	int i=0, j=0,c_count=0;
	for(i=0; i<array_size-1; i++){
		for(j=array_size-1; j>=i; j--){
			if(array[j]<array[j-1]){
				swap(&array[j],&array[j-1]);
				c_count++;
			}
		}
	}
	*count=c_count;
}

int main(){
	int size=0,count=0;;
	scanf("%d",&size);
	int array[100]={};
	for(int i=0; i<size; i++){
		scanf("%d",&array[i]);
	}
	bubble_sort(array,size,&count);
	for(int i=0; i<size-1; i++){
		printf("%d ",array[i]);
	}
	printf("%d\n%d\n",array[size-1],count);
	return 0;
}


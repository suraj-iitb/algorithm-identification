#include<stdio.h>
/*ALDS1_1_A:Insertion Sort*/
int main(void)
{
	int array_length;
	int array[100]={0};
	int temp;
	int i,j,k;
	
	scanf("%d",&array_length);
	for(i=0;i<array_length;i++){
		scanf("%d",&array[i]);
	}
	
	for(i=0;i<array_length-1;i++){
		printf("%d ",array[i]);
	}
	printf("%d\n",array[array_length-1]);
	
	for(i=1;i<array_length;i++){
		temp=array[i];
		j=i-1;
		while((j>=0)&&(array[j]>temp)){
			array[j+1]=array[j];
			j--;
			array[j+1]=temp;
		}
		for(k=0;k<array_length-1;k++){
			printf("%d ",array[k]);
		}
		printf("%d\n",array[array_length-1]);
	}
}

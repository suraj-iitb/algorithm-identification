#include <stdio.h>

void printarray(int array[],int n){
	int i;
	for(i=0;i<n;++i){
		if(i)printf(" ");
		printf("%d",array[i]);
	}
	printf("\n");
}

int main(void){
	int n,i,j,key;
	int array[100];
	scanf("%d",&n);
	
	for(i=0;i<n;++i)
		scanf("%d",&array[i]);
		
	printarray(array,n);
	for(i=1;i<n;++i){
		key = array[i];
		j=i-1;
		while(j>=0&&array[j]>key){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
		printarray(array,n);
	}
	return 0;
}

#include <stdio.h>

int main(void) {
	
	int i,j,n,k;
	int key;
	int array[100];


	scanf("%d",&n);

	for(i =0;i < n;i++){
		scanf("%d",&array[i]);
	}

	for(k =0;k < n;k++){
		if(k < n-1){
			printf("%d ",array[k]);
		}else{
			printf("%d",array[k]);
		}
		
	}
	printf("\n");
	
	for(i = 1;i < n;i++){
		key = array[i];
		j = i -1;
		while((j >= 0) && (array[j] > key)){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		
		for(k =0;k < n;k++){
			if(k < n-1){
				printf("%d ",array[k]);
			}else{
				printf("%d",array[k]);
			}
		}
		printf("\n");
	}
	
	return 0;
}


#include <stdio.h>
int main(void){
	int n;
	int num[100];
	
	int key;
	
	int i,j,k;
	//input n
	scanf("%d",&n);
	
	//intput numbers
	for(i = 0;i < n;i++){
		scanf("%d",&num[i]);
	}
	//sort
	for(j = 0;j < n;j++){
		key = num[j];
		i = j-1;
		for(i > 0;num[i] > key;i--){
			num[i+1] = num[i];
		}
		num[i+1] = key;
		//display
		for(k = 0;k < n;k++){
			printf("%d",num[k]);
			if(k < n-1){
				printf(" ");
			}else{
				printf("\n");
			}
		}
		
	}
	
	
	
	
	return 0;
}

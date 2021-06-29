#include <stdio.h>

int main(){
	int arrLen;
	scanf("%d", &arrLen);
	int arr[arrLen];
	int i = 0;
	while (i < arrLen && scanf("%d", &arr[i]) == 1){
		i++;
	}
	for(int i = 1; i < arrLen; i++){
		for(int k = 0; k < arrLen; k++){
			printf("%d", arr[k]);
			if(k == arrLen - 1){
                		;
			}
			else {
		        	printf(" ");
		    	}
		}
		printf("\n");
		int temp = arr[i];
		int j = i - 1;
		while(j > -1 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	for(int k = 0; k < arrLen; k++){
		printf("%d", arr[k]);
		if(k == arrLen - 1){
			;
		}
		else {
		    printf(" ");
		}
	}
	printf("\n");
	return 0;
}

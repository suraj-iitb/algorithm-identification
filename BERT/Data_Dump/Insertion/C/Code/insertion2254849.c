#include <stdio.h>

int main(){
	
	int count;
	int i,j,k;
	int target_value;
	
	scanf("%d", &count);
	
	int *input_data = (int *)malloc(sizeof(int) * count);
	
	for(i = 0; i < count; i++){
		scanf("%d", input_data + i);
	}
	
	for(i = 1; i < count; i++){
		
		for(k = 0; k < count; k++){
			
			if(k == count - 1){
				printf("%d\n", input_data[k]);
			}
			else{
				printf("%d ", input_data[k]);
			}
		}
		
		
		
		target_value = input_data[i];
		j = i - 1;
		
		while(j >= 0 && input_data[j] > target_value){
			input_data[j + 1] = input_data[j];
			j--;
		}
		
		input_data[j + 1] = target_value;
		

	
	}
	
	for(k = 0; k < count; k++){
		if(k == count - 1){
			printf("%d\n", input_data[k]);
		}
		else{
			printf("%d ", input_data[k]);
		}
	}
			
	
	free(input_data);
	
	return 0;
	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_sort(int array[], int array_size);
void print_array(int array[], int array_size);

int main(void){
	int i,num_count,val[100];
	char buf[512],*ch;
	
	fgets(buf, sizeof(buf), stdin);
  	sscanf(buf, "%d\n", &num_count);

	fgets(buf,sizeof(buf),stdin);
	ch = strtok(buf," ");
	for (i = 0;i < 100;i++) {
		if (ch == NULL) {
			break;
		} else {
			val[i] = atoi(ch);
		}
		ch = strtok(NULL," ");
	}
	print_array(val, num_count);
	array_sort(val, num_count);
}

void array_sort(int array[], int array_size){
	for(int i = 1; i < array_size; i++){
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
		print_array(array, array_size);
	}
}

void print_array(int array[], int array_size){
	for (int i = 0; i < array_size;i++){
		printf("%d",array[i]);
		if (i != array_size - 1){
			printf(" ");
		} else{
			printf("\n");
		}
	}
}

#include <stdio.h>

#define N 100

void display(int data[], int n);
void insertionSort(int data[], int n);

int main(){
	
	int data[N];
	int i, n;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		
		scanf("%d", &data[i]);
		
	}
	
	display(data, n);
	
	insertionSort(data, n);
	
	return 0;
	
}


void display(int data[], int n){
	
	int i;
	for(i=0; i<n; i++){
		if(i>0){
			printf(" ");
		}
		printf("%d", data[i]);
	}
	
	printf("\n");
	
	return;
}



void insertionSort(int data[], int n){
	
	int i, j, temp;
	
	for(i=1; i<n; i++){
		
		j = i;
		temp = data[j];
		
		while(j>0 && temp < data[j-1]){
			
			data[j] = data[j-1];
			j--;
			
		}
		data[j] = temp;
		display(data, n);
	}
	
}

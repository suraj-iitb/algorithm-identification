#include <stdio.h>

void trace(int x[], int n){
	
	int i;
	
	for ( i = 0; i < n - 1; i++ ){
		if ( i >= 0 ){
			printf("%d ", x[i]);
		}
	}
	printf("%d\n",x[n - 1]);
}


void insertionSort(int x[], int n){
	int j, i, v;
	for ( i = 1; i < n; i++){
		v = x[i];
		j = i - 1;
		while ( j >= 0 && x[j] > v ){
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = v;
		trace(x, n);
	}
}

int main(void){
	int n, i, j, x[100];
	
	scanf("%d", &n);
	for ( i = 0; i < n; i++ ){
		scanf("%d", &x[i]);
	}
		trace(x, n);
		insertionSort(x, n);
		
		return 0;
}

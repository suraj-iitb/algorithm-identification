#include<stdio.h>

void insertion_sort( int a[], int b ){
	int i, j, v;
	
	for( i = 1; i < b; i++ ){
		v = a[i];
		j = i - 1;
		
		while( j >= 0 && a[j] > v ){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		
		for( int s = 0; s < b; s++){
			printf("%d", a[s]);
			if(s != b-1){
			    printf(" ");
			}
		}
		printf("\n");
	}
}	

int main(void){
	int x, i;
	
	scanf("%d", &x);
	
	int a[x];
	
	for( i = 0; i < x; i++ ){
		scanf("%d", &a[i]);
	}
	
	for( int i = 0; i < x; i++){
		printf("%d", a[i]);
		if(i != x-1){
		    printf(" ");
		}
	}
	printf("\n");
	
	insertion_sort( a, x );
	
	return 0;
}

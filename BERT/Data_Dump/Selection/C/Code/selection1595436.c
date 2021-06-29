#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2){
	int tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int select_sort(int *data, int size){
	int swap_count = 0;
	int i,j,minj;

	for(i=0;i<size;i++){
		minj = i;
		for(j=i;j<size;j++){
			if( data[j] < data[minj] ){
				minj = j;
			}
		}
		if( i != minj ){
			swap(data+i,data+minj);
			swap_count++;
		}
	}

	return swap_count;
}

int main(int argc, char** argv){
	int n,*data,i,swap_count;

	// Input
	scanf("%d",&n);
	data = malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",data+i);
	}

	// Sort
	swap_count = select_sort(data,n);

	// Output
	printf("%d",data[0]);
	for(i=1;i<n;i++){
		printf(" %d",data[i]);
	}
	putchar('\n');
	printf("%d\n",swap_count);

	// Reset
	free(data);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int *data, int size){
	int swap_count = 0;
	int swap_done;
	int i;
	int tmp;

	swap_done=1;
	while(swap_done){
		swap_done=0;
		for(i=size-1;i>=1;i--){
			if( data[i] < data[i-1] ){
				tmp = data[i];
				data[i] = data[i-1];
				data[i-1] = tmp;
				swap_done = 1;;
				swap_count++;
			}
		}
	}

	return swap_count;
}

int main(int argc, char** argv){
	int n,*data;
	int i;
	int swap_count;

	// Input
	scanf("%d",&n);
	data = malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",data+i);
	}
	
	// Sort
	swap_count = bubble_sort(data,n);
	
	// Output
	printf("%d",data[0]);
	for(i=1;i<n;i++){
		printf(" %d",data[i]);
	}
	printf("\n");
	printf("%d\n",swap_count);

	// Release
	free(data);

	return 0;
}

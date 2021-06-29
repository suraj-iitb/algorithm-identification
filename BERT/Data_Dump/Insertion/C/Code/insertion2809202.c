#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(){
	int n;
	int *data;
	int i, j, k;
	int v;

	scanf("%d", &n);
	data = (int *)malloc(sizeof(int) * n);

	for(i=0; i<n; i++){
		scanf("%d", &data[i]);
	}

	for(k=0; k< n; k++){
		if(k>0){
			printf(" ");
		}
		printf("%d", data[k]);
	}
	printf("\n");
	
	for(i=1; i< n; i++){
		v = data[i];
		j = i - 1;
		while((j>=0) && data[j]>v){
			data[j+1] = data[j];
			j = j - 1;
		}
		data[j+1] = v;

		for(k=0; k< n; k++){
			if(k>0){
				printf(" ");
			}
			printf("%d", data[k]);
		}
		printf("\n");
	}


	free(data);
	return 0;
}

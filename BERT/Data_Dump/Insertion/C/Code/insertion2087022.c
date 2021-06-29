#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int *card = NULL;
	int i,j,k;
	int temp;

	scanf("%d",&n);
	card = (int *)malloc(4*n);
	for(i=0;i<n;i++){
		scanf("%d",&card[i]);
	}
	for(i=0;i<n-1;i++){
		printf("%d ",card[i]);
	}
	printf("%d\n",card[n-1]);
	for(i=1;i<n;i++){
		temp = card[i];
		j = i - 1;
		while(j>=0 && card[j] > temp){
			card[j+1] = card[j];
			j--;
			card[j+1] = temp;
		}
		for(k=0;k<n-1;k++){
			printf("%d ",card[k]);
		}
		printf("%d\n",card[n-1]);
	}
	free(card);
}

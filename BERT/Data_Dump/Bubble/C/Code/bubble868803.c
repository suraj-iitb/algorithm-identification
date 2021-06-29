#include <stdio.h>

int main(void){
	int N;
	int num[100];
	int key;
	
	int count = 0;
	
	int i,j;
	//Input N
	scanf("%d",&N);
	
	//Input Numbers
	for(i = 0;i < N;i++){
		scanf("%d",&num[i]);
	}
	
	//Bubble Sort
	for(i = 0;i < N-1;i++){
		for(j = N-1;j > i;j--){
			if(num[j] < num[j-1]){
				key = num[j];
				num[j] = num[j-1];
				num[j-1] = key;
				count++;
			}
		}
	}
	
	//Display Numbers
	for(i = 0;i < N;i++){
		printf("%d",num[i]);
		if(i < N-1){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",count);
return 0;
}

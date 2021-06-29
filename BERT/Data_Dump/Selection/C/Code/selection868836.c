#include <stdio.h>

int main(void){
	int N;
	int num[100];
	int key;
	
	int mini;
	int count = 0;
	
	int i,j;
	
	scanf("%d",&N);
	
	for(i = 1;i <= N;i++){
		scanf("%d",&num[i]);
	}
	
	for(i = 1;i <= N;i++){
		mini = i;
		for(j = i;j <= N;j++){
			if(num[j] < num[mini]){
				mini = j;
			}
		}
		if(num[i] != num[mini])count++;
		key = num[i];
		num[i] = num[mini];
		num[mini] = key;
	}
	
	for(i = 1;i <= N;i++){
		printf("%d",num[i]);
		if(i < N){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",count);
		
		
return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	int *inputs;
	int cnt = 0;

	scanf("%d", &N);

	inputs = (int*)malloc(sizeof(int) * N);
	if(inputs == NULL){
		printf("Memory Error\n");
		exit(1);
	}

	for(int i = 0;i < N;i++){
		scanf("%d", &inputs[i]);
	}

	int temp;
	for(int i = N - 1; 0 < i; i--){
		for(int j = 0; j < i; j++){
			if(inputs[j + 1] < inputs[j]){
				temp = inputs[j + 1];
				inputs[j + 1] = inputs[j];
				inputs[j] = temp;
				cnt++;
			}
		}
	}

	for(int i = 0;i < N - 1;i++){
		printf("%d ", inputs[i]);
	}
	printf("%d", inputs[N - 1]);
	printf("\n%d\n", cnt);

}

#include <stdio.h>


int main()
{
	int N;
	int box[100];
	int min_pos, count;
	int i, j;


	scanf("%d", &N);

	for(i = 0; i < N; i++)
		scanf("%d", &box[i]);


	count = 0;
	for(i = 0; i < N; i++){
		min_pos = i;
		for(j = i + 1; j < N; j++){
			if(box[j] < box[min_pos])
				min_pos = j;
		}
		if(i != min_pos){
			box[i] ^= box[min_pos];
			box[min_pos] ^= box[i];
			box[i] ^= box[min_pos];
			count++;
		}
	}

	for(i = 0; i < N; i++){
		printf("%d", box[i]);
		if(i != N - 1)
			printf(" ");
	}
	printf("\n%d\n", count);

	return 0;
}

#include <stdio.h>


int main()
{
	int box[100];
	int N;
	int count;
	int i, j;


	scanf("%d", &N);

	for(i = 0; i < N; i++)
		scanf("%d", &box[i]);

	count = 0;
	for(i = 0; i < N; i++){
		for(j = N - 1; j > i; j--){
			if(box[j - 1] > box[j]){
				box[j] ^= box[j - 1];
				box[j - 1] ^= box[j];
				box[j] ^= box[j - 1];
				count++;
			}
		}
	}

	for(i = 0; i < N; i++){
		printf("%d", box[i]);
		if(i != N - 1)
			printf(" ");
	}
	printf("\n%d\n", count);;;

	return 0;
}

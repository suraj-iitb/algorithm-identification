#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n;
	int *box;
	int *count;
	int max, num;
	int i, j;


	scanf("%d", &n);

	box = (int *)malloc(sizeof(int) * n);

	max = -1;
	for(i = 0; i < n; i++){
		scanf("%d", &box[i]);
		if(box[i] > max)
			max = box[i];
	}

	count = (int *)malloc(sizeof(int) * max + 1);
	for(i = 0; i <= max; i++)
		count[i] = 0;

	// 数値カウント
	for(i = 0; i < n; i++)
		count[box[i]]++;

	// 表示
	for(i = 0; i <= max; i++){
		num = count[i];
		if(num != 0){
			for(j = 0; j < num; j++){
				printf("%d", i);
				if(j != num - 1)
					printf(" ");
			}
			if(i != max)
				printf(" ");
		}
	}
	printf("\n");

	return 0;
}

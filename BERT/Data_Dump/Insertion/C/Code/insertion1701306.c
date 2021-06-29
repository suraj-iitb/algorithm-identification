#include <stdio.h>

int main(void)
{
	int n;
	int i, j, k;
	int num[100];
	int sort;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	
	for (i = 0; i < n; i++){
		for (k = 0; k < n; k++){
			printf("%d", num[k]);
			if (k < n - 1){
				printf(" ");
			}
		}
		printf("\n");
		
		for (j = 0; j < i + 1; j++){
			if (num[i + 1] < num[j]){
				sort = num[j];
				num[j] = num[i + 1];
				num[i + 1] = sort;
			}
		}
	}
	
	return (0);
}

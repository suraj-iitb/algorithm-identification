#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int* a = (int *)malloc(sizeof(int) * n);
	int ch,k=0;

	while(scanf("%d", &ch) != EOF){
		a[k] = ch;
		k++;
	}

	int flag = 1;
	int change_count = 0;
	while(flag){
		flag = 0;
		for (int j = n-1; j > 0; j--)
		{
			if(a[j] < a[j-1])
			{
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
				flag = 1;
				change_count ++;
			}
		}
	}

	for(int j = 0; j < n; j++){
		printf("%d", a[j]);
		if(j != n-1) printf(" ");
	}
	printf("\n");
	printf("%d\n", change_count);
	return 0;
}

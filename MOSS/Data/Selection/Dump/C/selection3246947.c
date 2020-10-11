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

	int change_count = 0;

	for (int i = 0; i < n; i++)
	{
		int minj = i;
		for (int j = i; j < n; j++)
		{
			if(a[j] < a[minj])
			{
				minj = j;
			}
		}
		if(i != minj){
			int tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			change_count ++;
		}
	}

	for(int j = 0; j < n; j++){
		printf("%d", a[j]);
		if(j != n-1) printf(" ");
	}
	printf("\n%d\n", change_count);

	return 0;
}

#include <stdio.h>

//printf array
void printArray(int *a, int num){
	int i;
	for(i = 0; i <= num-2; i++)
	{
		printf("%d ", a[i]);
	}
	printf("%d", a[num-1]);
}

int main()
{
	int a[100];
	int N, i, j, v;

	while(scanf("%d", &N) == 1)
	{
		for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
		}
		
		for(i = 0; i <= N-1; i++)
		{
			v = a[i];
			j = i - 1;
			while(j >= 0 && a[j] > v)
			{
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = v;

			printArray(a,N);
			puts("");
		}
	}
	
	return 0;
}

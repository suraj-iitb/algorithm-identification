#include <stdio.h>

void selectionSort(int x[], int N)
{
	int i, j, minj, tmp;
	int cnt = 0;
	for(i=0; i<N; i++){
		minj = i;
		for(j=i; j<N; j++){
			if(x[j] < x[minj])
			{
				minj = j;
			}
		}
		tmp = x[i];
		x[i] = x[minj];
		x[minj] = tmp;
		if(i != minj) cnt++;
	}
	for(i=0; i<N; i++){
		if(i != N-1)
		{
			printf("%d ", x[i]);
		}
		else printf("%d", x[i]);
	}
	printf("\n");
	printf("%d\n", cnt);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	
	int i, x[n];
	for(i=0; i<n; i++){
		scanf("%d", &x[i]);
	}
	
	selectionSort(x, n);
	
	return 0;
}


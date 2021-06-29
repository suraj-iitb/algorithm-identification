#include <stdio.h>

void bubbleSort(int x[], int N)
{
	int i, j, tmp;
	int cnt=0;
	for(i=0; i<N-1; i++){
		for(j=N-1; j>i; j--){
			if(x[j] < x[j-1])
			{
				tmp = x[j];
				x[j] = x[j-1];
				x[j-1] = tmp;
				cnt++;
			}
		}
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
	bubbleSort(x, n);
	
	return 0;
}

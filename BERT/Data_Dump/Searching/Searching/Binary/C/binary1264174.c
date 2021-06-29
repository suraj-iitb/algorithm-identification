#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key){
	int pl = 0;
	int pr = n-1;

	do{
		int pc = (pl + pr) / 2;
		if (a[pc] == key){
			return 1;
		}else if (a[pc] < key){
			pl = pc + 1;
		}else{
			pr = pc - 1;
		}
	}while(pl <= pr);

	return -1;
}

int main(void)
{
	int i, j, nx, ny, k;
	int count = 0;
	int *x, *y;

	//S???????´???°??\???
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	//S?????´??°??????
	for (i = 0; i < nx; i++)
	{
		scanf("%d", &x[i]);
	}

	//T???????´???°??\???
	scanf("%d", &ny);
	y = calloc(ny, sizeof(int));

	//T?????´??°??????
	for (j = 0; j < ny; j++)
	{
		scanf("%d", &y[j]);
	}

	//??????C??????
	for (k = 0; k < ny; k++)
	{
		if (bin_search(x , nx, y[k]) == 1){
			count += 1;
		}
	}
	printf("%d\n", count);

	free(x);
	free(y);

	return 0;
}

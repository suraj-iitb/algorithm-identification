#include <stdio.h>

#define MAX 100

int n, a[MAX], cnt;

void selectionSort()
{
	int i, j, tmp, minj;
	cnt = 0;
	
	for (i = 0; i <= n-1; i++) {
		minj = i;
		
		for (j = i; j <= n - 1; j++) {
			if (a[j] < a[minj]) {
				minj = j;
				
			}
		}
		
		tmp = a[i];
		a[i] = a[minj];
		a[minj] = tmp;
		
		if (i != minj) {
			cnt++;
		}
	}
	
}

int main()
{
	int i;
	
	scanf("%d\n",&n);
	
	for (i = 0; i < n; i++) {
		 scanf ("%d",&a[i]);
	}
	
	selectionSort();
	
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
			}
		printf("%d",a[i]);
	}
	printf("\n");
	
	printf("%d\n",cnt);
return 0;
}

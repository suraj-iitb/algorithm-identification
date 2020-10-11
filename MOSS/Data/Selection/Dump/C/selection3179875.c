#include<stdio.h>
#include<string.h>

void trace(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (0 < i && i < n)printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int selectionsort(int a[], int n) {
	int i, j;
	int minnum;
	int min;
	int count = 0;

	for (i = 0; i < n - 1; i++) {
		min = a[i];
		minnum = i;
		for (j = i + 1; j < n; j++) {
			if (a[j]< min) {
				min = a[j];
				minnum = j;
			}
			
		}
		if (min != a[i]) {
			a[minnum] = a[i];
			a[i] = min;
			count++;
		}
	}
	   
	return count;
	
}




int main(void){

	int a[101];
	int n, i;
	int count;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	count = selectionsort(a, n);
	trace(a, n);
	printf("%d\n", count);


	return 0;
}

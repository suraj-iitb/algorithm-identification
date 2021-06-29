#include<stdio.h>

int selectionSort(int *a, int n) 
{
	int i, j, minj, temp;
	int count = 0;
	
	for(i=0;i<n;i++) {
		minj = i;
		for(j=i+1;j<n;j++) {
			if(a[j] < a[minj]) {
			    minj = j;
			}
		}
		if(i != minj) {
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
			count++;
		}
	}
	
	return count;
}

void print_array(int *a, int n) 
{
	int i;
	for(i=0;i<n;i++) {
		if(i > 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(void) 
{
	int n, a[100], i, count;
	
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	
	count = selectionSort(a, n);
	print_array(a, n);
	printf("%d\n", count);
	return 0;
}

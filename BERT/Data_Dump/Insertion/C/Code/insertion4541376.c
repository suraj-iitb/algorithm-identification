#include <stdio.h>
#include <string.h>

void insertionSort(int *a, int n);
void printArray(int *a, int n);
void swap(int *a, int *b);

int main(void)
{
	int i;
	int n;
	int a[1000];
	
	scanf("%d", &n);
	
	memset(a, 0, sizeof(a));
	
	for (i = 0; i < n; i++){
		scanf(" %d", &a[i]);
	}
	
	insertionSort(a, n);
	
	return (0);
}

void insertionSort(int *a, int n)
{
	int i;
	int tmpIndex;
	
	printArray(a, n);
	
	for (i = 1; i < n; i++){
		tmpIndex = i;
		while ((tmpIndex > 0) && (*(a + tmpIndex - 1) > *(a + tmpIndex))){
			swap((a + tmpIndex - 1), (a + tmpIndex));
			tmpIndex--;
		}
		printArray(a, n);
	}

}

void printArray(int *a, int n)
{
	int i;
	
	for (i = 0; i < n; i++){
		printf("%d%c", *(a + i), (i == (n - 1))? '\n' : ' ');
	}
}

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

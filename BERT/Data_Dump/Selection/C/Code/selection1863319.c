
#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *a, int n);
int selectionSort(int *a, int n);
void swapInt(int *a, int *b);

int main() {
	int n;
	int *a;
	int i,cnt;
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	cnt = selectionSort(a, n);

	for (i = 0; i < n; i++) {
		printf("%d", *(a + i));
		if (i != n - 1)printf(" ");
	}
	printf("\n");
	printf("%d\n",cnt);
	return 0;
}

int selectionSort(int *a,int n) {
	int swapCount = 0;
	int i, j, minj;
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
                if(i!=minj){
		    swapInt(&a[i], &a[minj]);
		    swapCount++;
                }
	}
	return swapCount;
}

void swapInt(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

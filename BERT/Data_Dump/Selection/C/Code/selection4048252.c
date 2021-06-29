#include<stdio.h>
#define N 100
int selectionSort(int a[], int n);

int main() {
	int a[N], n, i,k;

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	k = selectionSort(a, n);

	for (i = 0; i < n; i++) {
	  if(i > 0){
	    printf(" ");
	  }
		printf("%d", a[i]);
	}
	printf("\n");
	printf("%d\n",k);

	return 0;
}


int selectionSort(int a[], int n) {
  int i, j,minj,z,k = 0;
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
		  if (a[j] < a[minj]){
		    minj = j;
		  }
		}
		z = a[i];
		a[i] = a[minj];
		a[minj] = z;
		if (i != minj){
		 k++;
		}
	}
	return k;
}


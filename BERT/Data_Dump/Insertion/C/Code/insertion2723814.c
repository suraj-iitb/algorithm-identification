
#include <stdio.h>

/*
void insertionSort(int a[], int n) {
	int i;
	int v;
	int j;
	int k;
	for (i = 1; i<n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
	
		}
		for (k = 0; k<n; k++) {

			printf("%d ", a[k]);

		}
		printf("\b\n");
	}


}*/

int main(void)
{
	int a[1001];
	int n;
	int i;
	int k;
	int v;
	int j;
	scanf("%d", &n);
	for (i = 0; i<n; i++) {

		scanf("%d", &a[i]);

	}
	for(i=0;i<n;i++){ printf("%d",a[i]); if(i!=n-1) printf(" ");}
	printf("\n");
	for (i = 1; i<n; i++) {
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;

		}
		for (k = 0; k<n; k++) {

			printf("%d", a[k]);
			if(k!=n-1) printf(" ");

		}
			
			printf("\n");
	}


	return 0;
}



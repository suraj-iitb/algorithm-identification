#include<stdio.h>

int c = 0;

void merge(int a[], int left, int mid, int right)
{
	int i;
	int n1 = mid - left;
	int n2 = right - mid;
	int l[n1], r[n2];
	for( i = 0; i < n1; i++ ){
		l[i] = a[left+i];
	}
	for( i = 0; i < n2; i++ ){
		r[i] = a[mid+i];
	}
	
	l[n1] = 100000000000;
	r[n2] = 100000000000;
	
	int j = 0, k;
	i = 0;
	
	for( k = left; k < right; k++ ){
		c++;
		if( l[i] <= r[j] ){
			a[k] = l[i++];
		}else{
			a[k] = r[j++];
		}
	}
}

void mergeSort(int a[], int left, int right)
{
	if( left+1 < right ){
		int mid = (left+right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(void){
	int n, i;
	scanf( "%d", &n );
	int a[n];
	for( i = 0; i < n; i++ ){
		scanf( "%d", &a[i] );
	}
	
	mergeSort(a, 0, n);
	
	for( i = 0; i < n-1; i++ ){
		printf( "%d ", a[i] );
	}
	printf( "%d\n", a[n-1] );
	
	printf( "%d\n", c );
	
	return 0;
}

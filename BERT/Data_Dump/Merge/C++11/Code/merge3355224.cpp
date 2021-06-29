#include<stdio.h>
#include<climits>

int k = 0;

void Merge(long* a, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	long* L = new long[n1+1];
	long* R = new long[n2+1];
	for ( int i = 0; i < n1; i++) L[i] = a[left + i];
	L[n1] = LONG_MAX;
	for (int i = 0; i < n2; i++) R[i] = a[mid + i];
	R[n2] = LONG_MAX;
	int i = 0;
	int j = 0;
	while(i < n1 || j < n2){
		if (L[i] <= R[j]){
			a[left + i + j] = L[i];
			i++;
			k++;
		}
		else{
			a[left + i + j] = R[j];
			j++;
			k++;
		}
	}
}

void MergeSort(long* a, int left, int right){
	if (left + 1 < right){
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid, right);
		Merge(a, left, mid, right);
	}
}

int main(){
	int n = 0;
	scanf("%d", &n);
	long* a = new long[n];
	for (int i = 0; i < n; i++) scanf("%ld", &a[i]);
	MergeSort(a, 0, n);
	for ( int i = 0; i < n; i++){
		printf("%ld", a[i]);
		if (i != n-1) printf(" ");
	}
	printf("\n");
	printf("%d\n", k);
}

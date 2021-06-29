#include <stdio.h>
int SelectionSort(int a[],int n,int *m){
	int min,t;
	for (int k = 0;k < n;k ++){
		min = k;
		for (int j = k;j < n;j ++){
			if (a[j] < a[min]){
				min = j;
			}
			
		}
		if (min == k) *m -= 1;
		*m += 1;
		t = a[k];
		a[k] = a [min];
		a [min] = t;
	}
	return *m;
}
int main(){
	int n,m = 0;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; i ++){
		scanf("%d",&a[i]);
	} 
	SelectionSort (a,n,&m);
	for (int i = 0; i < n; i ++){
		if (i == (n - 1)) printf ("%d",a[i]);
		else printf("%d ",a[i]);
	} 
	printf("\n%d\n",m);
	return 0;
}


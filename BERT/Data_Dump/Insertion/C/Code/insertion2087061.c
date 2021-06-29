#include<stdio.h>

void view(int a[], int n){
	int i;
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}

void insertionSort(int a[], int n){
	int i,j,v;
	view(a,n);
	for(i=1;i<n;i++){
		v = a[i];
		j = i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		view(a,n);
	}
	
}

int main(void){
	int i,a[100],n;

	scanf("%d\n",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	insertionSort(a,n);

	return 0;
}

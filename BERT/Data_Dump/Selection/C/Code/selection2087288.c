#include<stdio.h>

void view(int a[], int n){
	int i;
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}

void selectionSort(int a[], int n){
	int i,j,temp,minj,count=0;
	for(i=0;i<n;i++){
		minj = i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj]) minj = j;
		}
		if(i!=minj){
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
			count++;
		}
	}
	view(a,n);
	printf("%d\n",count);
}

int main(void){
	int i,a[100],n;

	scanf("%d\n",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	selectionSort(a,n);

	return 0;
}

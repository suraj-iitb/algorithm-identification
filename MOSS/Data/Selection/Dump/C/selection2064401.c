#include<stdio.h>

int selectionSort(int a[],int n){

	int i,j,minj,temp;
	int sw=0;

	for(i=0;i<n-1;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj])
				minj=j;
		}
		temp=a[i];
		a[i]=a[minj];
		a[minj]=temp;
		if(i != minj)
			sw++;
	}
	return sw;
}

int main(){

	int a[100],n,i,sw;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	sw = selectionSort(a,n);

	for(i=0;i<n;i++){
		if(0<i)
			printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d\n",sw);
	
	return 0;
}

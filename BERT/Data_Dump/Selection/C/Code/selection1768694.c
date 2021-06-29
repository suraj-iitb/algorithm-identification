#include <stdio.h>

int Selectionsort(int a[], int n);
void swap(int *a, int *b);

int main(){
	int i,n,x;
	int a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	x=Selectionsort(a,n);
	for(i=0;i<=n-1;i++){
		if(i>0) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",x);
	return 0;
}

int Selectionsort(int a[], int n){
	int i,j;
	int count=0,min;
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(i!=min){
			swap(&a[i],&a[min]);
			count++;
		}
	}
	return count;
}

void swap(int *a, int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

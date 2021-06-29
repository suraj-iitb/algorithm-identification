#include <stdio.h>
#define MAX 100
void insertionSort(int *,int);
void printData(int *,int);
int main(void){
	int i,n;
	int a[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printData(a,n);
	insertionSort(a,n);

	return 0;
}
void insertionSort(int *a,int n){
	int i,j,v;
	
	for(i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0){
			if(v<a[j]){
				a[j+1]=a[j];
				j--;
			}
			else{
				break;
			}
		}
        a[j+1]=v;
		printData(a,n);
	}
}

void printData(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1){
			printf(" ");
		}
	}
	printf("\n");
}

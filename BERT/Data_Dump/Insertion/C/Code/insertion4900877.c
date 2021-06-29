#include <stdio.h>
#include <stdlib.h>
void insertionSort(int a[],int n);

int main(void){
	int n=0;
	int i=0;
    int a[100]={};
	
	
	scanf("%4d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	

	
	insertionSort(a,n);
	
	
	return 0;
}

void insertionSort(int a[],int n){
	int i=0;
	int v=0;
	int j=0;
	int k=0;
	
	for(i=0;i<n;i++){
	
		v=a[i];
		j=i-1;
		
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(k=0;k<n;k++){
		    if(k==n-1){
				printf("%d\n",a[k]);
			}
			else{
				printf("%d ",a[k]);
			}
			
		}

	}
}



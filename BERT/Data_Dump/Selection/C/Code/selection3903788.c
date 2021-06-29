#include<stdio.h>
#define N 100000

void SelectionSort(int a[],int array_size){
	int i;
	int j;
	int k;
	int min;
	int temp;
	int cnt=0;
	for(i=0;i<array_size-1;i++){
		min=i;
		for(j=i+1;j<array_size;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
	if(min!=i){cnt++;}	
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
	}
	for(k=0; k<array_size-1;k++){
		printf("%d ",a[k]);
	}
	for(k=array_size-1; k<array_size;k++){
		printf("%d\n",a[k]);
	}
        printf("%d\n",cnt);
}

int main(void){
	int i,n;
	int a[N];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	SelectionSort(a,n);

  return 0;
}

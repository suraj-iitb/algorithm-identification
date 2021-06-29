#include <stdio.h>

void selectionSort(int a[],int N);
int main(void){
	int i,N;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	selectionSort(a,N);
	return 0;
}

void selectionSort(int a[],int N){
	int i,min,j,count=0,tmp;
	for(i=0;i<=N-1;i++){
		min=i;
		for(j=i;j<=N-1;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		tmp=a[i];
		a[i]=a[min];
		a[min]=tmp;
		if(i!=min) count++;
	}
	
	for(i=0;i<N;i++){
	if(i>0)	printf(" ");
	printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",count);
}

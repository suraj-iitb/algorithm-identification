#include <stdio.h>

int selectionSort(int *,int);
void swap(int *,int *);
int main(void){
	int i,n;
	int count;
	int a[100];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	count=selectionSort(a,n);
	
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1)
			printf(" ");
	}
	printf("\n");
	printf("%d\n",count);
	
	
	return 0;
}

int selectionSort(int *a,int n){
	int i,j;
	int minj,count=0;
	
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj])
				minj=j;
		}
		if(a[i]!=a[minj]){
			swap(&a[i],&a[minj]);
			count++;
		}
	}
	
	return count;
}


void swap(int *px,int *py){
	int tmp=*px;
	*px=*py;
	*py=tmp;
}

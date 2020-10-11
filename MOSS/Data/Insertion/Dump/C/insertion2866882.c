#include <stdio.h>
void insertionSort(int a[],int n);

int main(void) {
	int a[1000],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	insertionSort(a,n);
	
	return 0;
}

void insertionSort(int a[],int n){
	int v,i,j,k;
	for(i=1;i<n;i++){
	    for(k=0;k<n;k++){
			printf("%d",a[k]);
			if(k==n-1) printf("\n");
			else printf(" ");
		}
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
	}
	for(k=0;k<n;k++){
	    printf("%d",a[k]);
		if(k==n-1) printf("\n");
		else printf(" ");
	}
	return ;
}

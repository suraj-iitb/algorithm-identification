#include <stdio.h>

int c;

void merge(int a[],int n,int l,int mid,int r){
	int n1,n2,i,j,k;
	n1 = mid - l;
	n2 = r - mid;
	int left[n1],right[n2];
	for(i=0;i<n1;i++){
		left[i] = a[l + i];
	}
	for(i=0;i<n2;i++){
		right[i] = a[mid + i];
	}
	left[n1] = right[n2] = 2000000000;
	i=0;
	j=0;
	for(k=l;k<r;k++){
		c++;
		if(left[i] <= right[j]){
			a[k] = left[i++];
		}else{
			a[k] = right[j++];
		}
	}
}

void mergeSort(int a[],int n,int l,int r){
	int mid;
	if(l+1 < r){
		mid = (l+r)/2;
		mergeSort(a,n,l,mid);
		mergeSort(a,n,mid,r);
		merge(a,n,l,mid,r);
	}
}

int main(void){
	int n,i;
	int s[500000];
	c = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	mergeSort(s,n,0,n);
	for(i=0;i<n;i++){
		printf("%d",s[i]);
		if(i!=n-1)printf(" ");
	}
	printf("\n%d\n",c);
}

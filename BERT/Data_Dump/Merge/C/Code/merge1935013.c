#include <stdio.h>
#define N 500000
#define INFTY 1000000001

int a[N];
int l[N],r[N];
int count=0;
void merge(int array[],int left,int mid,int right){
	int n1 = mid-left;
	int n2 = right-mid;
	int i,j,k;
	for(i=0;i<n1;++i) l[i]=array[left+i];
	for(i=0;i<n2;++i) r[i]=array[mid+i];
	l[n1] = r[n2] = INFTY;
	i=j=0;
	for(k=left;k<right;++k){
		count++;
		if(l[i]<=r[j]){
			array[k]=l[i];
			i++;
		}else{
			array[k]=r[j];
			j++;
		}
	}
}

void mergesort(int array[],int left,int right){
	if(left+1<right){
		int mid = (left+right)/2;
		mergesort(array,left,mid);
		mergesort(array,mid,right);
		merge(array,left,mid,right);
	}
}
		
int main(void){
	int n;
	int i;
	
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	
	mergesort(a,0,n);
	
	for(i=0;i<n;++i){
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d\n",count);
	return 0;
}

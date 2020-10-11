#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000000
#define L 1000000000

int cnt=0;
int a[N],w[N],r[N];

void merge(int A[],int left,int mid,int right){
	int n1 = mid-left;
	int n2 = right-mid;
	int i,j,k;
	for(i=0;i<n1;++i) w[i]=A[left+i];
	for(i=0;i<n2;++i) r[i]=A[mid+i];
	w[n1] = r[n2] = L;
	i=j=0;
	for(k=left;k<right;++k){
		cnt++;
		if(w[i]<=r[j]){
			A[k]=w[i];
			i++;
		}else{
			A[k]=r[j];
			j++;
		}
	}
}

void mergesort(int A[],int left,int right){
	
	if(left+1<right){
		
		int mid = (left+right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
}


int main(void){
    
	int n,i;

	scanf("%d",&n);
	for(i=0;i<n;++i){scanf("%d",&a[i]);}

	mergesort(a,0,n);
	for(i=0;i<n;++i){
		if(i!=0) {printf(" ");}
		printf("%d",a[i]);
	}
	
	printf("\n%d\n",cnt);
	return 0;
}


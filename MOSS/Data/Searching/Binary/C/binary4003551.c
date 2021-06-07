#include<stdio.h>

#define N_MAX 100000
#define Q_MAX 50000

int binarysearch(int n,int* a,int key){
	int l=0;
	int r=n;
	int mid;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid]==key){
			return mid;
		}else if(key<a[mid]){
			r=mid;
		}else{
			l=mid+1;
		}
	}return N_MAX+1;
}

int main(void){

	int A[N_MAX+1];
	int n;
	int B[Q_MAX+1];
	int q;
	int s=0;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&B[i]);
	}
	
	for(int i=0;i<q;i++){
		if(binarysearch(n,A,B[i])!=N_MAX+1)s++;

	}
	
	printf("%d\n",s);
	
	return 0;
}

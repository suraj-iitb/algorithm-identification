#include<stdio.h>

int BinarySearch(int A[],int n,int k){
	int L,M,R;
	L=0;
	R=n;
	while(L<R){
		M=(L+R)/2;
		if(A[M]==k){
			return 1;
		}
		if(A[M]<k){
			L=M+1;
		}else{
			R=M;
		}
	}
	return 0;
}

int main(){
	int n,q,k;
	int A[100000];
	int i;
	int a,s;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
    s=0;
	for(i=0;i<q;i++){
		scanf("%d",&k);
		a=BinarySearch(A,n,k);
		if(a==1){
			s++;
		}
	}
	
	printf("%d\n",s);
	return 0;
}

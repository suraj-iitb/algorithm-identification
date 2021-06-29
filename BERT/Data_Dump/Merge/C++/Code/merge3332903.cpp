#include<stdio.h>
#define M 500000
#define MM 2000000000

int L[M/2+2],R[M/2+2];
int cou;

void merge(int A[],int l,int r){
	int m=(l+r)/2;
	int n1=m-l;
	int n2=r-m;
	for(int i=0;i<n1;i++) L[i]=A[l+i];
	for(int i=0;i<n2;i++) R[i]=A[m+i];
	L[n1]=R[n2]=MM;
	int i=0,j=0;
	for(int k=l;k<r;k++){
		cou++;
		if(L[i]<=R[j]){
			A[k]=L[i++];
		}
		else A[k]=R[j++];
	}
}

void sort(int A[],int l,int r){
	if(l+1<r){
		int m=(l+r)/2;
		sort(A,l,m);
		sort(A,m,r);
		merge(A,l,r);
	}
}
int main(){
	int A[M],n,i,j;
	cou=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,0,n);
	printf("%d",A[0]);
	for(i=1;i<n;i++) printf(" %d",A[i]);
	printf("\n%d\n",cou);
} 

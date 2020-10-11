#include<stdio.h>
#include<limits.h>
int c=0;
void merge(int*A,int l,int m,int r){
	int *L,*R,n1,n2,i,j,k;
	n1=m-l;
	n2=r-m;
	L=(int*)malloc(sizeof(int)*(n1+1));
	R=(int*)malloc(sizeof(int)*(n2+1));
	for(i=0;i<n1;i++)L[i]=A[l+i];
	for(i=0;i<n2;i++)R[i]=A[m+i];
	L[n1]=R[n2]=INT_MAX;
	i=j=0;
	for(k=l;k<r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
		c++;
	}
	free(L);free(R);
}
void merge_sort(int*A,int l, int r){
	int m;
	if(l+1<r){
		m=(l+r)/2;
		merge_sort(A,l,m);
		merge_sort(A,m,r);
		merge(A,l,m,r);
	}
}
int main(){
	int i,n,*A;
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*(n));
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	merge_sort(A,0,n);
	for(i=0;i<n;i++)printf("%d%c",A[i],i==n-1?'\n':' ');
	printf("%d\n",c);
	return 0;
}

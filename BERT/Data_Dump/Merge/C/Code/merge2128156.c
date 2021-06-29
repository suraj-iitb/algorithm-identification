#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}

void merge(int *A,int left,int mid,int right,int *count){
	int n1,n2,i,j,k;
	int *L,*R;
	n1=mid-left;
	n2=right-mid;
	mymalloc(L,n1+1);
	mymalloc(R,n2+1);
	for(i=0;i<n1;i++){
		L[i]=A[left+i];
	}
	for(j=0;j<n2;j++){
		R[j]=A[mid+j];
	}
	L[n1]=INT_MAX;R[n2]=INT_MAX;
	i=0;j=0;
	for(k=left;k<right;k++){
			(*count)++;
		
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
	free(L);free(R);
}

void mergeSort(int *A,int left,int right,int *count){
	int mid;
	if(left+1<right){
		mid=(right-left)/2+left;
		mergeSort(A,left,mid,count);
		mergeSort(A,mid,right,count);
		merge(A,left,mid,right,count);
	}
}

main(){
	int i,count,n,*A;
	scanf("%d",&n);
	mymalloc(A,n);
	for(i=0;i<n;i++){
		scanf(" %d",&A[i]);
	}
	count=0;
	mergeSort(A,0,n,&count);
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i!=n-1){
			printf(" ");
		}
	}
	printf("\n");
	printf("%d\n",count);
	free(A);
	return 0;
}

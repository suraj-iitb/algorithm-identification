#include <stdio.h>

#define SENTINEL 2000000000 
#define MAX 500000
int L[MAX],R[MAX];
int count=0;
void Merge(int A[],int n,int left,int mid,int right);
void MergeSort(int A[],int n,int left,int right);

int main(void){

	int i,n;	
	int A[MAX];	
	scanf("%d",&n);
	for(i=0;i<n;i++){ scanf("%d",&A[i]); }
	MergeSort(A,n,0,n);
	for(i=0;i<n;i++){
		if(i){ printf(" "); }
		printf("%d",A[i]);
	}
	
	printf("\n%d\n",count);

	

return 0;
}


void Merge(int A[],int n,int left,int mid,int right){

	int i,j,k,n1,n2;

	n1 = mid - left;
	n2 = right - mid;
	
	for(i=0;i<n1;i++){ L[i] = A[left+i]; } 
	for(i=0;i<n2;i++){ R[i] = A[mid+i]; }
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	i = j = 0;
	for(k=left;k<right;k++){
		count++;
		if(L[i] <= R[j]){ 
			A[k] = L[i];
		    i++; 
		}else{
			A[k] = R[j];
			j++;
		}
	}
	
}

void MergeSort(int A[],int n,int left,int right){
    int mid;	
	if(left+1 < right){
		mid = (left + right)/2;
		MergeSort(A,n,left,mid);
		MergeSort(A,n,mid,right);
		Merge(A,n,left,mid,right);
	}
}


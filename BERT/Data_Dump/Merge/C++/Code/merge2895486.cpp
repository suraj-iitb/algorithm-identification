#include<iostream>
int cnt=0;
void merge(int A[],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	int L[500000],R[500000];
	for(int i=0;i<n1;i++){
		L[i]=A[left+i];
	}
	L[n1]=10000000000;
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	R[n2]=10000000000;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
			cnt++;
		}else{
			A[k]=R[j];
			j++;
			cnt++;
		}
	}
}
void mergeSort(int A[],int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}
int main(){
	int n,A[500000];
	std::cin>>n;
	for(int i=0;i<n;i++){
		std::cin>>A[i];
	}
	mergeSort(A,0,n);
	for(int i=0;i<n;i++){
		if(i!=n-1){
			std::cout<<A[i]<<" ";
		}else{
			std::cout<<A[i]<<"\n";
		}
	}
	std::cout<<cnt<<"\n";
	return 0;
}

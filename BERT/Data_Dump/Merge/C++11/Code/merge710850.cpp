#include <iostream>

using namespace std;

int num=0;

void Merge(int A[],int left,int mid,int right);
void MergeSort(int A[],int left,int right);

int main()
{
    int A[500000],N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	MergeSort(A,0,N);
	cout<<A[0];
	for(int i=1;i<N;i++){
		cout<<" "<<A[i];
	}
	cout<<endl<<num<<endl;
}

void Merge(int A[],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int dL[n1+1],dR[n2+1];
	for(int i=0;i<n1;i++){
		dL[i]=A[left + i];
	}
	for(int i=0;i<n2;i++){
		dR[i]=A[mid + i];
	}
	dL[n1]=1000000001;
	dR[n2]=1000000001;
	int i,j;
	for(i=left,j=0;i<right;i++){
		if(dL[i-left-j]<dR[j]){
			A[i]=dL[i-left-j];
		}else{
			A[i]=dR[j];
			j++;
		}
		num++;
	}
	
}
void MergeSort(int A[],int left,int right)
{
	if(left+1<right){
		int mid=(left+right)/2;
		MergeSort(A,left,mid);
		MergeSort(A,mid,right);
		Merge(A,left,mid,right);
	}
}

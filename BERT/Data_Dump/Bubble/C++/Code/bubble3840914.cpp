#include <iostream>
#include <cstdio>
using namespace std;

int sw=0;

void outputArray(int A[],int n){
	for(int i=0;i<n-1;i++)
		cout<<A[i]<<" ";
	cout<<A[n-1]<<endl;
}

void bubbleSort(int A[], int n){
	bool flag=1;
	for(int i=0;flag;i++){
		flag = 0;
		for(int j=n-1;j>i;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				flag = 1;
				sw++;
			}
		}
//	outputSort(A,n);
	}
}

int main(){
	
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	bubbleSort(A,n);
	outputArray(A,n);
	cout<<sw<<endl;
	return 0;
} 
